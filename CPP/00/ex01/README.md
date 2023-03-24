# My AwesomePhoneBook

Welcome to the 80s and their unbelievable technology! Write a program that behaves
like a crappy awesome phonebook software.

You have to implement two classes:

## PhoneBook

- It has an array of contacts.
- It can store a maximum of **8 contacts**. If the user tries to add a 9th contact,
replace the oldest one by the new one.

Please note that **dynamic allocation is forbidden.**

## Contact

- Stands for a phonebook contact.
- In your code, the phonebook must be instantiated as an instance of the PhoneBook
class.

Same thing for the contacts. Each one of them must be instantiated as an instance
of the Contact class.

You’re free to design the classes as you like but keep in mind that
anything that will always be used inside a class is private, and that anything that can be
used outside a class is public.

___

On program start-up, the phonebook is empty and the user is prompted to enter one
of three commands. The program only accepts **ADD**, **SEARCH** and **EXIT**.

## **ADD**

- save a new contact
- If the user enters this command, they are prompted to input the information
of the new contact one field at a time.
- Once all the fields have been completed, add the contact to the phonebook.

## The contact field

1. first name
2. last name
3. nickname
4. phone number
5. darkest secret

A saved contact can’t have empty fields.

## **SEARCH**

- display a specific contact
- Display the saved contacts as a list of 4 columns: **index**, **first name**,
**last name** and **nickname**.

- Each column must be **10** characters wide and be separed by a pipe character (’|’)
- The text must be right-aligned.
- If the text is longer than the column, it must be truncated and the last displayable character must be replaced by a
dot (".").

- Then, prompt the user again for the index of the entry to display. If the index
is out of range or wrong, define a relevant behavior. Otherwise, display the
contact information, one field per line.

- **EXIT**
- The program quits and the contacts are lost forever!
- Any other input is discarded.

___

## Design requirements

### Contact.class

- have 5 private (so `_name`, etc.) for each field stored in a string.
- have setter / getter funcitons for all of them.

### PhoneBook.class

- ~~Have an `array` of Contacts (max 8).~~
- ~~Have a `function` to add a new contact.~~
- ~~Have a `function` to print out all the contacts.~~
- ~~have a `function` run phone_book to start the main stuff.~~
