# Parser

- Accept [99_03_parser](https://classroom.github.com/a/pGn6bI08)
- Get [basic_test.cpp](basic_test.cpp)

---

The SQL commands are store in the `string` type variable. `Parser` class can save each token into a `MultiMap` object.

For example:

```cpp
     input :    select lname, fname from student where lname = "Yao" and fname = "Flo"
   command :    select
 condition :    lname = Yao and fname = Flo
    fields :    lname fname
table_name :    student
     where :    yes
```

## Tasks

1. Modify `tokenizer` class to create a state machine for SQL commands.
2. Implement [Parser](parser.h) class to save tokens to MultiMap.
