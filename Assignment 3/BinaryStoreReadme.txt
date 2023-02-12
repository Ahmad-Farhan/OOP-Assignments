Contains 2 classes

1. Byte (char array of 9 bits)
2. BinaryStore (size, bits and associated address)

Byte class Function Logic

1.Byte Addition

initializes carry = 0;
loops through the bits of given Byte class variable starting from last digit(index = 7)
uses "ADD_Chars" function and sets resultant bit in res index

Add_chars takes two characters, converts them to integers 
Adds the numbers and a third carry integer
in an interger variable called result
reduces result till it is a binary value(0 or 1)
along with increasing carry everytime result is reduced

2.Byte SUbtraction

Confirms if one Byte is greater than the other or not
if not then returns default "11111111"
if subtractable then loops through the bits array 
checks if borrow is needed and determines borrow by loopin from 
given index till the point where a "1" is found,
changes that one to 0 and changes all the values till that index to "1"
the result is stores in resultant Byte variable;

3.Byte Logical Operators

Loops through given bits array of a byte
each bit is typecasted to a respective integer
and logical operation is performed between the two bits
boolean reqult is passed to "Logic" function which returns
a character value which is then stored in resultant byte.

4.Byte Equal-to Operator

Loops through array and compares each bit,
returns false if bits are unqual at any index
if loop ends with all values equal , return true

BinaryStore

1.Add
checks if the Byte at first index is empty(i.e., all values are null)
If first Byte is empty ,assigns given address to the respective address index
otherwise
Declare temporary BinarySTore initialized with "this" 
Initializes this to by entirely empty 
sets address value at empty index

2. += Operator
Does exactly as Add

3. = Operator
uses setters and getters to assign given values to "this" members