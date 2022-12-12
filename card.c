/****************************************************************************************************/
/*File Name:card.c																					*/
/*File Info:This file contains the function implementation of the Card module						*/
/*Version:V1.0																						*/
/*Author:Shereef Mahmoud Mohamed																	*/
/****************************************************************************************************/

#include"card.h"		

/****************************************************************************************************/
//this function is scanning the card holder name of the user.
EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	printf("please enter the cardholder's name \n");
	printf("*Max 24 alphabetic characters and Min 20*\n");
	scanf("%[^\n]s", cardData->cardHolderName); fflush(stdin);

	int len = strlen((char*)(cardData->cardHolderName));
	if (len > 24 || len < 20 || len == 0) {
		return WRONG_NAME;
	}
	for (int i = 0; cardData->cardHolderName[i] != NULL; i++) {
		if (cardData->cardHolderName[i] >= '0'&& cardData->cardHolderName[i]<='9') {
			return WRONG_NAME;
		}
	}
	
	return CARD_OK;
}
/****************************************************************************************************/


//this function is getting the card expiry date of the user's card.
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	printf("please enter the card expiy date in form of MM/YY: \n");
	scanf("%s", cardData->cardExpirationDate); fflush(stdin);
	int len = strlen((char*)(cardData->cardExpirationDate));
	if (len > 5 || len < 5 || len == 0) {
		return WRONG_EXP_DATE;
	}
	else if (cardData->cardExpirationDate[2] != '/' || cardData->cardExpirationDate[0]>'3') {
		return WRONG_EXP_DATE;
	}
	else if (cardData->cardExpirationDate[0] > '1' || (cardData->cardExpirationDate[0] == '1' && cardData->cardExpirationDate[1] > '2')) {
		return WRONG_EXP_DATE;
	}
	for (int i = 0; i < 5; i++) {
		if (i == 2) {
			continue;
		}
		else if (!(cardData->cardExpirationDate[i] >= '0' && cardData->cardExpirationDate[i] <= '9')) {
			return WRONG_EXP_DATE;
		}
	}
	
	return CARD_OK;
}
/****************************************************************************************************/


//this function gets the card PAN from the user.
EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	printf("please enter the Primary Account Number: \n");
	scanf("%s", cardData->primaryAccountNumber);
	int len = strlen((char*)(cardData->primaryAccountNumber));
	if (len > 19 || len < 16 || len == 0) {
		return WRONG_PAN;
	}
	for (int i = 0; i < len; i++) {
		if (!(cardData->primaryAccountNumber[i] >= '0' && cardData->primaryAccountNumber[i] <= '9')) {
			return WRONG_PAN;
		}
	}
	return CARD_OK;
}
/****************************************************************************************************/



//test for the module.
/*
int main() {
	ST_cardData_t s;
	printf("getCardHolderName-> %d\n", getCardHolderName(&s));
	printf("-------------------------------------\n");
	printf("getCardExpiryDate-> %d\n", getCardExpiryDate(&s));
	printf("-------------------------------------\n");
	printf("getCardPAN-> %d\n", getCardPAN(&s));
	printf("-------------------------------------\n");

}*/




