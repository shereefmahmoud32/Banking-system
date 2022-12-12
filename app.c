/****************************************************************************************************/
/*File Name:server.c																				*/
/*File Info:This file contains the function implementation of the Card module						*/
/*Version:V1.0																						*/
/*Author:Shereef Mahmoud Mohamed																	*/
/****************************************************************************************************/

#include"app.h"

int main() {
	appStart();
}

void appStart() {
	ST_cardData_t cardData;
	ST_terminalData_t termData;
	
	if (getCardHolderName(&cardData) == WRONG_NAME) {
		printf("Wrong Name");
		exit(0);
	}

	if (getCardExpiryDate(&cardData) == WRONG_EXP_DATE) {
		printf("Wrong Expiry Date");
		exit(0);
	}

	if (getCardPAN(&cardData) == WRONG_PAN) {
		printf("Wrong PAN");
		exit(0);
	}

	if (isValidCardPAN(&cardData) == INVALID_CARD) {
		printf("Invalid Card");
		exit(0);
	}

	if (getTransactionDate(&termData) == WRONG_DATE) {
		printf("Wrong Date");
		exit(0);
	}

	if (isCardExpired(&cardData, &termData) == EXPIRED_CARD) {
		printf("Declined Expired Date");
		exit(0);
	}

	if (getTransactionAmount(&termData) == INVALID_AMOUNT) {
		printf("Invalid Amount");
		exit(0);
	}

	setMaxAmount(&termData, 5000); // set the maximum allowed to 

	if (isBelowMaxAmount(&termData) == EXCEED_MAX_AMOUNT) {
		printf("Declinded Amount Exceeding Limit");
		exit(0);
	}

	ST_transaction_t transData;
	transData.cardHolderData = cardData;
	transData.terminalData = termData;


	int x = recieveTransactionData(&transData);
	saveTransaction(&transData);

	if (x == FRAUD_CARD) {
		printf("Declinded Invalid account");
		exit(0);
	}
	else if (x == DECLINED_INSUFFECIENT_FUND) {
		printf("Low Balance");
		exit(0);
	}
	else if (x == DECLINED_STOLEN_CARD) {
		printf("Blocked Card");
		exit(0);
	}
	else if (x == INTERNAL_SERVER_ERROR) {
		printf("server error");
		exit(0);
	}
	
	else if (x == APPROVED) {
		printf("Success Transaction\n");
		listSavedTransactions();
		exit(0);
	}
	
	//saveTransaction(&transData);
	//listSavedTransactions();


}