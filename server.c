/****************************************************************************************************/
/*File Name:server.c																				*/
/*File Info:This file contains the function implementation of the Card module						*/
/*Version:V1.0																						*/
/*Author:Shereef Mahmoud Mohamed																	*/
/****************************************************************************************************/

#include"server.h"

/****************************************************************************************************/
// declaration for the data base of the accounts in the server.

 ST_accountsDB_t accountsDB[255] = { {2000.0,RUNNING,"8989374615436851"},{100000.0, BLOCKED, "5807007076043875"},
	 {5000,RUNNING,"4847352989263094"},{500,BLOCKED,"2250577473437986"},{20000,RUNNING,"1757407903048502"} };

 //declatration for the database for the transactions done.

 ST_transaction_t transaction[255]={0};

 /****************************************************************************************************/

//declaration for the account reference to save the account in the DB to check the condion of the card. 
 ST_accountsDB_t accountReference;

 /****************************************************************************************************/
//this function recieves the transaction data and check the conditions of the transaction
 //and save any transaction done.
EN_transStat_t recieveTransactionData(ST_transaction_t* transData) {
		
		transData->transState = accountReference.state;

		if (isValidAccount(&transData->cardHolderData,& accountReference)== ACCOUNT_NOT_FOUND){
			//saveTransaction(&transData);
			return FRAUD_CARD;
		}
		else if (isAmountAvailable(&transData->terminalData, &accountReference) == LOW_BALANCE) {
			//saveTransaction(&transData);

			return DECLINED_INSUFFECIENT_FUND;
		}
		else if (isBlockedAccount(&accountReference) == BLOCKED_ACCOUNT) {
			//saveTransaction(&transData);

			return DECLINED_STOLEN_CARD;
		}
		else {
			for (int i = 0; i < 255; i++) {
				if (!strcmp(transData->cardHolderData.primaryAccountNumber, accountsDB[i].primaryAccountNumber)) {
					accountsDB[i].balance = accountsDB[i].balance - transData->terminalData.transAmount;
					printf("The new Balance is: [ %f ]\n", accountsDB[i].balance);
				}
				else if (strcmp(transData->cardHolderData.primaryAccountNumber, accountsDB[i].primaryAccountNumber)) {
					continue;
				}
			}
			//saveTransaction(&transData);

			return APPROVED;
		}
	
}

/****************************************************************************************************/
//this function is checking if the account is valid and saved in the data base of the bank or not
//and return the refernce of the account from the data base to the account reference.

EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence) {
	for (int i = 0; i < 255; i++) {
		if (!strcmp(cardData->primaryAccountNumber, accountsDB[i].primaryAccountNumber)) {
			*accountRefrence = accountsDB[i];
			return SERVER_OK;
		}
		else if (strcmp(cardData->primaryAccountNumber, accountsDB[i].primaryAccountNumber)) {
			continue;
		}
	}
	accountRefrence = NULL;
	return ACCOUNT_NOT_FOUND;
}


/****************************************************************************************************/
//this function checks if the account is blocked or running

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence) {
		if (accountRefrence->state==RUNNING) {
				return SERVER_OK;
			}
			else {
				return BLOCKED_ACCOUNT;
			}
		
}

/****************************************************************************************************/
//this function checks if the amount available in the account or not

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence) {
	if (termData->transAmount <= accountRefrence->balance) {
		return SERVER_OK;
	}
	else if (termData->transAmount > accountRefrence->balance) {
		return LOW_BALANCE;
	}
}

/****************************************************************************************************/
//declaration for the transactions number to know the sequence and number of transaction done.

int transaction_number = 0;

/****************************************************************************************************/
//this function saves the transactions done in the transaction data base.

EN_serverError_t saveTransaction(ST_transaction_t* transData) {
	if (transaction_number < 255) {
		transaction[transaction_number].cardHolderData = transData->cardHolderData;
		transaction[transaction_number].terminalData = transData->terminalData;
		transaction[transaction_number].transState = transData->transState;
		transaction[transaction_number].transactionSequenceNumber = transaction_number;
	}
	transData->transState = accountReference.state;
	++transaction_number;
	return SERVER_OK;
}

/****************************************************************************************************/
//this function prints the transactions in the transaction database.

void listSavedTransactions(void) {
	for (int i = 0; i < 5; i++) { // i<5 to print the transactions info and 5 is instead of 255 to be able to see the saved transactions.
		printf("#########################\n");
		printf("Transaction Sequence Number:%d\n", transaction[i].transactionSequenceNumber);
		printf("Transaction Date: %s\n", transaction[i].terminalData.transactionDate);
		printf("Transaction Amount:%f\n", transaction[i].terminalData.transAmount);
		printf("Transaction State:%d\n", transaction[i].transState);
		printf("Terminal Max Amount:%f\n", transaction[i].terminalData.maxTransAmount);
		printf("Cardholder Name:%s\n", transaction[i].cardHolderData.cardHolderName);
		printf("PAN:%s\n", transaction[i].cardHolderData.primaryAccountNumber);
		printf("Card Expiration Date:%s\n", transaction[i].cardHolderData.cardExpirationDate);
		printf("#########################\n");

	}
}
/*
int main() {
	ST_transaction_t t;
	t.terminalData.maxTransAmount = 5000;
	t.terminalData.transAmount = 1000;
	ST_cardData_t c;
	strcpy(c.primaryAccountNumber,"8989374615436851");
	printf("is valid -> [ %d ]\n",isValidAccount(&c, &accountReference));
	printf("is blocked account -> [ %d ]\n", isBlockedAccount(&accountReference));
	printf("is amount available ->[ %d ]\n", isAmountAvailable(&t, &accountReference));
	printf("receive transaction -> [ %d ]\n", recieveTransactionData(&t));
	printf("save transaction -> [%d] \n", saveTransaction(&t));

	listSavedTransactions();
}

*/
