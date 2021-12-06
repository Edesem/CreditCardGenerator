I decided to go on a tangent on the cs50 course and adapted the credit card validator to create a valid credit card generator, so yeah although its very basic and only can generate AMEX, MASTERCARD and VISA.

It has a bug where the card numbers will have usually three zeros after the inital card type identifier
eg) Output: 5100001873982207 instead of something more random like
            5138131873982207
            
            
This is because either I don't fully know the capabilities of the rand() function and I'm not creative enough yet or the function is limited when it comes to 13, 15 and 16 digit long numbers
