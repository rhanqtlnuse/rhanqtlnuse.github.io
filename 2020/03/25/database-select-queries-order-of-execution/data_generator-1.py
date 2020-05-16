#!/usr/bin/env python

# -*- coding: utf8 -*-

import random

import mysql.connector as mysql

conn = mysql.connect(
    host="localhost",
    username="rhanqtl",
    password="0000"
)

cursor = conn.cursor()

DEFAULT_NUM_RECORDS = 1000000

LOWER_CASE_LETTERS = [chr(i) for i in range(ord('a'), ord('z') + 1)]
UPPER_CASE_LETTERS = [chr(i) for i in range(ord('A'), ord('Z') + 1)]


def _random_lower_case_letter():
    return random.choice(LOWER_CASE_LETTERS)


def _random_upper_case_letter():
    return random.choice(UPPER_CASE_LETTERS)


def _generate_first_names(num_records=DEFAULT_NUM_RECORDS):
    print("Generating first names ...")
    first_names = []
    for _ in range(num_records):
        first_names.append(
            "".join([_random_upper_case_letter()] + 
                    [_random_lower_case_letter()
                     for _ in range(random.randint(2, 9))]))
    print("Done!")
    return first_names


def _generate_last_names(num_records=DEFAULT_NUM_RECORDS):
    print("Generating last names ...")
    last_names = []
    for _ in range(num_records):
        last_names.append(
            "".join([_random_upper_case_letter()] + 
                    [_random_lower_case_letter()
                     for _ in range(random.randint(2, 9))]))
    print("Done!")
    return last_names


def prepare_for_insert(records):
    return ", ".join(list(map(lambda e: f"('{e}')", records)))


def insert(table_name, columns, data):
    print("Inserting into database ...")
    columns = f"({', '.join(list(map(lambda e: f'`{e}`', columns)))})"
    data = prepare_for_insert(data)
    sql_query = f"INSERT INTO {table_name} {columns} VALUES {data};"
    # print(sql_query)
    cursor.execute(sql_query)
    conn.commit()
    print("Done!")


def generate_names(num_records=DEFAULT_NUM_RECORDS):
    return (_generate_first_names(num_records=num_records), 
            _generate_last_names(num_records=num_records))


if __name__ == '__main__':
    cursor.execute(
        """
        CREATE TABLE IF NOT EXISTS `test`.`first_names` (
            PRIMARY KEY(`name_id`),
            `name_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
            `name`    VARCHAR(20)  NOT NULL
        ) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4
        """)
    cursor.execute(
        """
        CREATE TABLE IF NOT EXISTS `test`.`last_names` (
            PRIMARY KEY(`name_id`),
            `name_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
            `name`    VARCHAR(20)  NOT NULL
        ) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4
        """)
    
    first_names, last_names = generate_names()
    num_iter = 100
    batch_size = DEFAULT_NUM_RECORDS // num_iter
    for i in range(100):
        insert("`test`.`first_names`", ["name"], first_names[i: i + batch_size])
        insert("`test`.`last_names`", ["name"], last_names[i: i + batch_size])

    cursor.close()
    conn.close()
