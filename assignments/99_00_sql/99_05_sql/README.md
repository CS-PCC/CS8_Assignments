# SQL

- Accept [99_05_sql](https://classroom.github.com/a/0ruFe-sk)
- Get [basic_test.cpp](basic_test.cpp)

---

The SQL class manages all the tables that has been created in this system (this includes previous sessions). It will provide a command line interface to allow the user to issue sql commands (create, insert and select). You will combine `parser`, `table`, and `binary_files` together to process SQL commands in this project.

## SQL Class

You need to implement [sql](sql.h) class to process SQL commands in both `string` as inputs.

The SQL class will also provide a batch mode: Constructor will take a file name, [_!sample01.txt](_!sample01.txt) as argument an will execute these commands within, compare with the [sample output](_!sample01_output.txt).

### Batching process

```sql
create table student fields last, first, major
insert into student values Yang, Bo, “Computer Science”
insert into student values Davis, John, Math
insert into student values Johnson, “Mary Ann”, “Biology”

create table employee fields lname, fname, dept, hireyear
insert into employee values Jackson, David, Finance, 2016
insert into employee values Davidson, “Mary Alice”, complaints, 2012
```

### Output of batching

```cpp
//******************************************************************************
//		LOGICAL OPERATORS
//******************************************************************************

//.................
//:AND            :
//.................
[28] > select * from studentSample01 where fname = "Flo" and lname = "Yao"
Table name: _select_table_25, records: 1
                   record                    fname                    lname                    major                      age
                        0                      Flo                      Yao                       CS                       20
records selected: 0

//.................
//:OR            :
//.................
[29] > select * from studentSample01 where fname = Flo or lname = Jackson
Table name: _select_table_26, records: 2
                   record                    fname                    lname                    major                      age
                        0                      Flo                      Yao                       CS                       20
                        1                      Flo                  Jackson                     Math                       21
records selected: 0 1
```

1. There are lines of text in the batch file that begin with two slashes: `//`, these lines must be printed back to the screen and ignored by your SQL class.
2. Number your queries starting from zero.
3. The output of the select statement must contain the table name (temporary table), the number of records, and records selected. Make sure the output prints in columns.
4. Each record is numbered starting from zero. These are not the record numbers in the original table, but the record numbers in the selected table.

## Presentation

You will use [_!sample02.txt](_!sample02.txt) to test your program for submission and for presentation. Also, you should be able to enter SQL command in command prompt to operate database.
