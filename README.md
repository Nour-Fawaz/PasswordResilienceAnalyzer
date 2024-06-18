# Password Resilience Analyzer

* **Creator**: [Nour Fawaz](fawazn@mcmaster.ca)
* **Program**: B. Eng. In Software Engineering
* **Course code**: SFWRENG 2XC3
* **Course Title**: Software Engineering Practice and Experience: Development Basics
* Term: *Level II - Fall 2024*


# About The Prpgram

The program asses the strength of a given password based on a predetermined set of rules and guidelines.

## Program Features
The program has a main interface displaying three options; testing a password, viewing the strength of a previously tested password, and exiting the program.

To select an option, simply type the number of the option beside `Please select an option: `.

```
Password Resilience Analyzer
1. Test a new password
2. View streng of previously tested password
3. Exit
Please select an option:
```

## How a Password is Evaluated

Strong Passwords are considered to contain the following:

- Lowercase letter
- Uppercase letter
- Numerical digit
- Special character: !@#$%^&*()
- 12+ Characters

Each of the criteria above contribute a point to the overall score of the password:

- 0-2 points: Weak
- 3-4 points: Moderate
- 5 points: Strong
