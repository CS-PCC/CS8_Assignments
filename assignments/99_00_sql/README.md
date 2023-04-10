# Capstone Project: Database (SQL)

## Overview

In this project, you'll be building a small version of what is called a relational database management system (DBMS), as well as a DSL (Domain Specific Language) with which a user can interact with your database. The language you will be implementing is similar to the declarative programming language SQL, which is used in the real world to interact with and query databases, large or small. Below is an example of a table.

| last_name | first_name | major |
| :-------- | :--------- | :---- |
| Lee | Maurice | Math |
| Lee | Maurice | CS |
| Ray | Mitas | Music |
| Hwang | Alex | Business |
| Rulison | Jared | Management |
| Fang | Vivian | Music |

## Commands

There are several commands you'll have to support in your database implementation. They each have specific error conditions but there are some errors that multiple share. When relevant, this includes malformed commands, commands that result in illegal operations within the database and commands involving tables that don't exist (except create table). Any command that errors should result in no change to the database.

### Create Table

```sql
create table <TABLE_NAME> fields <FIELD_NAME> [, <FIELD_NAME> ...]

e.g.
create table employee fields last_name, first_name, major
```

Create a table with the given name. The names and types of the columns of the new table are supplied in a parenthesized list, in order. This defines the column order for this table.

It is an error to create a table with no columns and it is also an error to create a table that already exists.

Create Table should return the empty String on success, or an appropriate error message otherwise.

### Insert Into

```sql
insert into <TABLE_NAME> values <VALUE> [, <VALUE> ...] 

e.g.
insert into employee values Blow, Joe, CS
insert into employee values "Jackson", Billy, Math
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
select first_name, last_name from student
select * from student
select * from student where last_name
select * from student where age < 23
select * from student where last_name = Yang and age < 23
select * from student where (last_name = Yang or major = CS) and age < 23
select * from student where not last_name = Yang and not major = CS
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
- not

## Your Task

You are responsible for implementing the behavior described in the spec.

1. [`99_01_binary_files`](99_01_binary_files/)
2. [`99_02_table`](99_02_table/)
3. [`99_03_tokenizer`](99_03_tokenizer/)
4. [`99_04_parser`](99_04_parser/)
5. [`99_05_sql`](99_05_sql/)

## Reference

- [Implement more functionalities](http://sp17.datastructur.es/materials/proj/proj2/proj2.html)
- [SQL Tutorial](https://www.w3schools.com/sql/)
