/*#include"terminal.h"
//void getTransactionDateTest(void);
//void isCardExpriedTest(void);
//void getTransactionAmountTest(void);
//void isBelowMaxAmountTest(void);
//void setMaxAmountTest(void);
void isValidCardPANTest(void);
int main() {
	//getTransactionDateTest();
	//isCardExpriedTest();
	//getTransactionAmountTest();
	//isBelowMaxAmountTest();
	//setMaxAmountTest();
	isValidCardPANTest();
}
/*void getTransactionDateTest(void) {
	ST_terminalData_t t;
	printf("Tester Name: Shereef Mahmoud\n");
	printf("Function Name: getTransactionDateTest\n");
	printf("Test Case 4: \n");
	printf("input Data: 2/2/2022 \n");
	printf("Expected Result: WRONG_DATE= 1\n");
	printf("Actual Result:%d \n", getTransactionDate(&t));
}*/
/*void isCardExpriedTest(void) {
	ST_cardData_t c;
	ST_terminalData_t t;
	strcpy(c.cardExpirationDate, "08/22");
	strcpy(t.transactionDate, "18/08/2023");
	
	printf("Tester Name: Shereef Mahmoud\n");
	printf("Function Name: isCardExpriedTest\n");
	printf("Test Case 4: \n");
	printf("input Data: 18/08/2023,08/22 \n");
	printf("Expected Result: EXPIRED_CARD =2\n");
	printf("Actual Result:%d \n", isCardExpired(&c,&t));

}*/
/*void getTransactionAmountTest(void) {
	ST_terminalData_t t;
	printf("Tester Name: Shereef Mahmoud\n");
	printf("Function Name:getTransactionAmountTest");		
	printf("Test Case : 4\n");
	printf("input Data: ahh \n");
	printf("Expected Result: INVALID_AMOUNT 0\n");
	printf("Actual Result:%d \n", getTransactionAmount(&t));
}
*/
/*void isBelowMaxAmountTest(void) {
	ST_terminalData_t t; 
	t.maxTransAmount = 15000;
	t.transAmount = 1000;
	printf("Tester Name: Shereef Mahmoud\n");
	printf("Function Name: isBelowMaxAmountTest\n");
	printf("Test Case : \n");
	printf("input Data: \n");
	printf("Expected Result: TERMINAL_OK= 0\n");
	printf("Actual Result:%d \n", isBelowMaxAmount(&t));
}*/
/*void setMaxAmountTest(void) {
	ST_terminalData_t t;
	printf("Tester Name: Shereef Mahmoud\n");
	printf("Function Name: setMaxAmountTest\n");
	printf("Test Case 4: \n");
	printf("input Data: -4 \n");
	printf("Expected Result: INVALID_MAX_AMOUNT = 6\n");
	printf("Actual Result:%d \n", setMaxAmount(&t,-4));
}*/
/*void isValidCardPANTest(void) {
	ST_cardData_t t;
	strcpy(t.primaryAccountNumber, "4847352989263094");
	printf("Tester Name: Shereef Mahmoud\n");
	printf("Function Name: isValidCardPANTest\n");
	printf("Test Case 2: \n");
	printf("input Data: 4847352989263095 \n");
	printf("Expected Result: INVALID_CARD= 3\n");
	printf("Actual Result:%d \n", isValidCardPAN(&t));
}*/