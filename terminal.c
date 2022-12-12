/****************************************************************************************************/
/*File Name:terminal.c																				*/
/*File Info:This file contains the function implementation of the terminal module					*/
/*Version:V1.0																						*/
/*Author:Shereef Mahmoud Mohamed																	*/
/****************************************************************************************************/

#include"terminal.h"

/****************************************************************************************************/
//this function gets the transaction date from the user

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	printf("please enter the Transaction date in form of DD/MM/YYYY: \n");
	scanf("%s",termData->transactionDate); fflush(stdin);
	int len = strlen((char*)(termData->transactionDate));
	if (len < 10 || len == 0) {
		return WRONG_DATE;
	}
	else if (termData->transactionDate[2] != '/' || termData->transactionDate[5]!='/') {
		return WRONG_DATE;
	}
	else if (termData->transactionDate[0] > '3' || termData->transactionDate[3] > '1') {
		return WRONG_DATE;
	}
	else if ((termData->transactionDate[0] == '3' &&  termData->transactionDate[1]>'1')||(termData->transactionDate[3]=='1'&&termData->transactionDate[4]>'2')){
		return WRONG_DATE;
	}
	for (int i = 0; i < 5; i++) {
		if (i == 2 || i == 5) {
			continue;
		}
		else if (!(termData->transactionDate[i] >= '0' && termData->transactionDate[i] <= '9')) {
			return WRONG_DATE;
		}
	}
		return TERMINAL_OK;
	}


/****************************************************************************************************/
//this function checks if the card is expired or not.

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) {
	
	if (termData->transactionDate[8] > cardData->cardExpirationDate[3]) {
		return EXPIRED_CARD;
	}
	else if (termData->transactionDate[9] > cardData->cardExpirationDate[4]) {
		return EXPIRED_CARD;
	}
	else if ((termData->transactionDate[3] > cardData->cardExpirationDate[0]) || (termData->transactionDate[4] > cardData->cardExpirationDate[1])) {
		return EXPIRED_CARD;
	}
	else {
		return TERMINAL_OK;
	}
}


/****************************************************************************************************/
//this function gets the transaction amount from the user.

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
	printf("please enter the amount of transaction: \n"); fflush(stdin);
	scanf("%f",&termData->transAmount); fflush(stdin);
	if (termData->transAmount <= 0) {
		return INVALID_AMOUNT;
	}

	return TERMINAL_OK;
}


/****************************************************************************************************/
//this function checks if the amount needed is below the max amount allowed or not.

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
	if (termData->transAmount > termData->maxTransAmount) {
		return EXCEED_MAX_AMOUNT;
	}
	return TERMINAL_OK;
}


/****************************************************************************************************/
//this function is used to set the maxAmount allowed for transaction.

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount) {
	termData->maxTransAmount = maxAmount;
	if (termData->maxTransAmount <= 0) {
		return INVALID_MAX_AMOUNT;
	}
	return TERMINAL_OK;
}


/****************************************************************************************************/
//this function is used to check is the card PAN number is valid or not.

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData) {
	int sum_odd = 0, sum_even = 0; int res = 0; int s = 0;
	for (int i= (strlen(cardData->primaryAccountNumber)-1); i >= 0; i--) {
		if ((i%2)!= 0) {
			sum_odd = sum_odd + cardData->primaryAccountNumber[i]-'0';
		}
		else if((i%2)==0)
		{
			int x = cardData->primaryAccountNumber[i] - '0';
			x = x * 2;
			if (x < 10) {
				sum_even = sum_even + x;
			}
			else if (x > 9) {
				s = 0;
				while (x != 0) {
					res = x % 10;
					s = res + s;
					x = x / 10;
				}
				sum_even = sum_even + s;

			}
		}
	}
	if ((sum_even + sum_odd) % 10 == 0) {
		return TERMINAL_OK;
	}
	else
		return INVALID_CARD;
}

//test for the module.
/*
int main() {
	ST_terminalData_t t;
	ST_cardData_t c;
	strcpy(c.primaryAccountNumber,"8989374615436851");
	strcpy(c.cardExpirationDate, "08/22");
	printf("get transation Date -> [ %d ]\n", getTransactionDate(&t));
	printf("is Card Expired -> [ %d ]\n",isCardExpired(&c, &t));
	printf("get transaction amount -> [ %d ]\n",getTransactionAmount(&t));
	printf("set Max Amount -> [ %d ]\n", setMaxAmount(&t, 500));
	printf("is isBelowMaxAmount -> [ %d ]\n", isBelowMaxAmount(&t));
	printf("\nisValidCardPAN -> [ %d ]\n", isValidCardPAN(&c));

}*/
