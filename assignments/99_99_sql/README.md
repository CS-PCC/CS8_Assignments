# Capstone Project: Database (SQL)

## Overview

In this project, you'll be building a small version of what is called a relational database management system (DBMS), as well as a DSL (Domain Specific Language) with which a user can interact with your database. The language you will be implementing is similar to the declarative programming language SQL, which is used in the real world to interact with and query databases, large or small. Below is an example of a table.

| Lastname string | Firstname string | TeamName string |
| :-------------- | :--------------- | :-------------- |
| Lee | Maurice | Mets |
| Lee | Maurice | Steelers |
| Ray | Mitas | Patriots |
| Hwang | Alex | Cloud9 |
| Rulison | Jared | EnVyUs |
| Fang | Vivian | Golden Bears |

## Commands

There are several commands you'll have to support in your database implementation. They each have specific error conditions but there are some errors that multiple share. When relevant, this includes malformed commands, commands that result in illegal operations within the database and commands involving tables that don't exist (except create table). Any command that errors should result in no change to the database.

### Create Table

```sql
create table <TABLE_NAME> fields <FIELD_NAME> [, <FIELD_NAME> ...]

e.g.
create table employee fields last, first, department
```

Create a table with the given name. The names and types of the columns of the new table are supplied in a parenthesized list, in order. This defines the column order for this table.

It is an error to create a table with no columns and it is also an error to create a table that already exists.

Create Table should return the empty String on success, or an appropriate error message otherwise.

### Insert Into

```sql
insert into <TABLE_NAME> values <VALUE> [, <VALUE> ...] 

e.g.
insert into employee values Blow, Joe, CS
```

Insert the given row (the list of literals) to the named table. The table must already be in the DB and the provided values must match the columns of that table. If a provided value cannot be parsed into the type of the column it is listed in, it is an error. The given row is appended to the table, becoming the last row in its row order.

It is an error to insert a row that does not match the given table.

Insert Into should return the empty String on success, or an appropriate error message otherwise.

### Select

Select statements are used to extract data from the database in a programmatic fashion. Instead of simply writing to and printing individual tables, select statements allow you to form more complicated requests. They take the form below:

```sql
select <* | FIELD_NAME> [, <FIELD_NAME> ...]
from <TABLE_NAME>
where <FIELD_NAME> <RELATIONAL_OPERATOR> <VALUE> [<LOGICAL_OPERATOR> <FIELD_NAME> <RELATIONAL_OPERATOR> <VALUE> ...]

e.g.
select * from student where lname = Yang or major = CS and age < 23
```

The result of a select statement is a new table that has been formed from the join of the given table(s), filtered by the conditional statement(s), and selected from with the column expression(s). The order in which these operations happen is up to your implementation, as long as the output is correct. The joining of tables is optional, i.e. selecting from a single table is valid. The conditional statements are also optional.

The order of the columns in the new table is defined by the order they are listed in the select. In the case that all columns are selected (with the * operator), the order is defined by the column order for the join.

It is an error to write a select statement that involved no columns of the listed tables.

Select should return the String representation of the produced table, or an appropriate error message otherwise.

## A Note on Whitespace

Arbitrary amounts of whitespace are allowed to exist within a command, as long as they delimit parts of the command. That is, arbitrary whitespace may exist between column names, operators, keywords, etc. As an example, the following queries are all valid and equivalent:

```sql
select a,b from table1, table2
select      a,b from table1, table2
select a , b from table1    ,table2
select a,         b    from table1,table2
         select a   , b from table1,table2
```

While whitespace should not matter in commands, it does matter in your output. There should be no spaces between fields in your output format. The only spaces should be inside the quotes of string values, and a single space in between a column name and its type.

## Definitions

### NAME

Table and filed names are non-empty sequences of characters. They may contain only letters, numbers and underscores, and must start with a letter. In addition, no keywords (words involved in commands) may be used as table names, but you don't have to handle this case.

### VALUE

A string of alphanumeric characters, or a string of alphanumeric characters and spaces enclosed by double quotation marks: "Jean Louise", Finch, 1923

### RELATIONAL_OPERATOR

Valid conditional comparators are `=`, `!=`, `<`, `>`, `<=` and `>=`. These behave the same way that they do in the C++ programming language, allowing for translation to the proper compareTo constructs for Strings.

It is an error to compare strings to either int or float types, but it is valid to compare an int and a float.

### LOGICAL_OPERATOR

- and
- or

## Special Values

There are two different kinds of special values you'll have to handle in your implementation. These are NaN and NOVALUE.

### NaN

If a column expression results in a divide by zero error, the value in that row should be the string "NaN", unquoted. A NaN value has the same type as the column it exists in.

Any arithmetic operation that has a NaN value as one of its operands should produce a NaN. Any comparison operators involving NaN should treat it as being larger than all other values except itself, to which it should be equal. NaN may not be given as a literal in a column expression or an insert. You do not have to handle this.

### NOVALUE

The special value NOVALUE is exactly what it sounds like, it represents the absence of a value. The value present in a database row should be the string "NOVALUE", unquoted. A NOVALUE value has the same type as the column it exists in.

Any arithmetic operation that has a NOVALUE as one of its operands should treat it as the zero value for the column type. The zero values for strings, ints and floats are '', 0 and 0.0, respectively. The one exception to this is when both operands to arithmetic are NOVALUE, in this case the result should also be NOVALUE. Any comparison operation that has a NOVALUE as one of its operands should evaluate to false. NOVALUE may not be given as a literal in a column expression. You do not have to handle this.

## Your Task

You are responsible for implementing the behavior described in the spec.

1. [`99_01_binary_file`](99_01_binary_file/)
2. [`99_02_table`](99_02_table/)
3. [`99_03_tokenizer`](99_03_tokenizer/)
4. [`99_04_parser`](99_04_parser/)
5. [`99_99_sql`](99_99_sql/)

## Reference

- [Reference](http://sp17.datastructur.es/materials/proj/proj2/proj2.html)
- [Practice](https://www.w3schools.com/sql/)