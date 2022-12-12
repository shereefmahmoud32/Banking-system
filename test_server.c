/*#include"server.h"
//void isValidAccountTest(void);
//void isBlockedAccountTest(void);
//void isAmountAvailableTest(void);
void saveTransactionTest(void);
void listSavedTransactionsTest(void);
/*int main() {
	//isValidAccountTest();
	//isBlockedAccountTest();
	//isAmountAvailableTest();
	saveTransactionTest();
	listSavedTransactionsTest();
	}*/
/*void isValidAccountTest(void) {
	ST_accountsDB_t t;
	ST_cardData_t c;
	strcpy(c.primaryAccountNumber, "89354zx54368");
	printf("Tester Name: Shereef Mahmoud\n");
	printf("Function Name: isValidAccountTest\n");
	printf("Test Case 4: \n");
	printf("input Data: *89354zx54368* \n");
	printf("Expected Result: ACCOUNT_NOT_FOUND  = 3\n");
	printf("Actual Result:%d \n", isValidAccount(&c,&t));
}*/
/*void isBlockedAccountTest(void) {
	ST_accountsDB_t a;
	strcpy(a.primaryAccountNumber, "5807007076043875");
	printf("Tester Name: Shereef Mahmoud\n");
	printf("Function Name: isBlockedAccountTest\n");
	printf("Test Case 4: \n");
	printf("input Data: *5807007076043875* \n");
	printf("Expected Result: BLOCKED_ACCOUNT = 5\n");
	printf("Actual Result:%d \n", isBlockedAccount(&a));
}*/
/*void isAmountAvailableTest(void) {
	ST_terminalData_t t;
	t.transAmount = 300.5;
	ST_accountsDB_t a;
	a.balance = 400.5;
	printf("Tester Name: Shereef Mahmoud\n");
	printf("Function Name: isAmountAvailableTest\n");
	printf("Test Case 3: \n");
	printf("input Data: *400.5* \n");
	printf("Expected Result: SERVER_OK= 0\n");
	printf("Actual Result:%d \n", isAmountAvailable(&t,&a));
}*/
/*void saveTransactionTest(void) {
	ST_transaction_t t;
	strcpy(t.cardHolderData.cardHolderName, "Shereef Mahmoud Mohamed");
	strcpy(t.cardHolderData.primaryAccountNumber, "8989374615436851");
	strcpy(t.cardHolderData.cardExpirationDate, "08/22");
	t.terminalData.maxTransAmount = 5000;
	t.terminalData.transAmount = 1000;
	strcpy(t.terminalData.transactionDate, "18/08/2022");
	t.transState = RUNNING; 
	saveTransaction(&t);
	/*printf("Tester Name: Shereef Mahmoud\n");
	printf("Function Name: saveTransactionTest\n");
	printf("Test Case 1: \n");
	printf("input Data: t \n");
	printf("Expected Result: SERVER_OK  = 0\n");
	printf("Actual Result:%d \n", saveTransaction(&t));
	/*printf("-------------------------\n");*/
	/*ST_transaction_t t2 = t;
	saveTransaction(&t2);*/
	/*printf("Tester Name: Shereef Mahmoud\n");
	printf("Function Name: saveTransactionTest\n");
	printf("Test Case 1: \n");
	printf("input Data: t \n");
	printf("Expected Result: SERVER_OK  = 0\n");
	printf("Actual Result:%d \n", );*/


/*void listSavedTransactionsTest(void) {
	
	listSavedTransactions();
}*/

