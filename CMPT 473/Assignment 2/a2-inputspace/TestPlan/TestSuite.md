# Test Suite #
*  Degree of interaction coverage: 2
*  Number of parameters: 28
*  Maximum number of values per parameter: 5
*  Number of configurations: 25


## Test Cases ##

### Configuration #1: ###


```sh
1 = input_file_type=plaintext
2 = input_file_size=small
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=false
18 = arrays_flag_set=false
19 = remove_empty_objects_flag_set=false
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=false
22 = output_template_name_specified=false
23 = dimensional_separator_specified=false
24 = delimiter_character_specified=false
25 = boolean_columns_specified=false
26 = numeric_columns_specified=false
27 = output_redirected=to_file
28 = record_field_data=only_non_ascii
```

-------------------------------------

### Configuration #2: ###


```sh
1 = input_file_type=plaintext
2 = input_file_size=medium
3 = csv_syntax_is_valid=true
4 = records_contain_same_number_of_fields=true
5 = record_contains_trailing_comma=true
6 = record_field_contains_space=true
7 = record_field_escaped=true
8 = record_field_contains_comma=true
9 = record_field_contains_new_line=true
10 = record_field_contains_double_quotes=true
11 = contents_contain_arrays=true
12 = contents_contain_empty_objects=true
13 = contents_contain_empty_strings=true
14 = contents_contain_nested_objects=true
15 = delimited_by_specified_character=true
16 = dimensionally_separated_by_specified_character=true
17 = contents_empty=false
18 = arrays_flag_set=true
19 = remove_empty_objects_flag_set=true
20 = remove_empty_strings_flag_set=true
21 = output_directory_specified=true
22 = output_template_name_specified=true
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=true
25 = boolean_columns_specified=true
26 = numeric_columns_specified=true
27 = output_redirected=to_command
28 = record_field_data=contains_both
```


-------------------------------------

### Configuration #3: ###


```sh
1 = input_file_type=plaintext
2 = input_file_size=large
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=false
18 = arrays_flag_set=true
19 = remove_empty_objects_flag_set=true
20 = remove_empty_strings_flag_set=true
21 = output_directory_specified=true
22 = output_template_name_specified=true
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=true
25 = boolean_columns_specified=true
26 = numeric_columns_specified=true
27 = output_redirected=to_standard_output
28 = record_field_data=only_ascii
```


-------------------------------------

### Configuration #4: ###


```sh
1 = input_file_type=plaintext
2 = input_file_size=none
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=true
18 = arrays_flag_set=false
19 = remove_empty_objects_flag_set=true
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=true
22 = output_template_name_specified=false
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=false
25 = boolean_columns_specified=true
26 = numeric_columns_specified=false
27 = output_redirected=to_file
28 = record_field_data=contains_both
```


-------------------------------------

### Configuration #5: ###


```sh
1 = input_file_type=non_plaintext
2 = input_file_size=small
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=false
18 = arrays_flag_set=false
19 = remove_empty_objects_flag_set=false
20 = remove_empty_strings_flag_set=true
21 = output_directory_specified=false
22 = output_template_name_specified=true
23 = dimensional_separator_specified=false
24 = delimiter_character_specified=true
25 = boolean_columns_specified=false
26 = numeric_columns_specified=true
27 = output_redirected=to_command
28 = record_field_data=only_ascii
```


-------------------------------------

### Configuration #6: ###


```sh
1 = input_file_type=non_plaintext
2 = input_file_size=medium
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=false
18 = arrays_flag_set=true
19 = remove_empty_objects_flag_set=false
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=false
22 = output_template_name_specified=false
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=false
25 = boolean_columns_specified=false
26 = numeric_columns_specified=false
27 = output_redirected=to_standard_output
28 = record_field_data=only_non_ascii
```


-------------------------------------

### Configuration #7: ###


```sh
1 = input_file_type=non_plaintext
2 = input_file_size=large
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=false
18 = arrays_flag_set=false
19 = remove_empty_objects_flag_set=false
20 = remove_empty_strings_flag_set=true
21 = output_directory_specified=true
22 = output_template_name_specified=false
23 = dimensional_separator_specified=false
24 = delimiter_character_specified=true
25 = boolean_columns_specified=true
26 = numeric_columns_specified=false
27 = output_redirected=to_file
28 = record_field_data=contains_both
```


-------------------------------------

### Configuration #8: ###


```sh
1 = input_file_type=non_plaintext
2 = input_file_size=none
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=true
18 = arrays_flag_set=true
19 = remove_empty_objects_flag_set=true
20 = remove_empty_strings_flag_set=true
21 = output_directory_specified=false
22 = output_template_name_specified=true
23 = dimensional_separator_specified=false
24 = delimiter_character_specified=false
25 = boolean_columns_specified=false
26 = numeric_columns_specified=true
27 = output_redirected=to_command
28 = record_field_data=only_non_ascii
```


-------------------------------------

### Configuration #9: ###


```sh
1 = input_file_type=multiple
2 = input_file_size=small
3 = csv_syntax_is_valid=true
4 = records_contain_same_number_of_fields=true
5 = record_contains_trailing_comma=true
6 = record_field_contains_space=false
7 = record_field_escaped=true
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=true
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=true
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=true
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=true
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=false
18 = arrays_flag_set=false
19 = remove_empty_objects_flag_set=false
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=false
22 = output_template_name_specified=false
23 = dimensional_separator_specified=false
24 = delimiter_character_specified=true
25 = boolean_columns_specified=false
26 = numeric_columns_specified=false
27 = output_redirected=to_standard_output
28 = record_field_data=contains_both
```


-------------------------------------

### Configuration #10: ###


```sh
1 = input_file_type=multiple
2 = input_file_size=medium
3 = csv_syntax_is_valid=true
4 = records_contain_same_number_of_fields=true
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=true
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=true
12 = contents_contain_empty_objects=true
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=true
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=true
17 = contents_empty=false
18 = arrays_flag_set=false
19 = remove_empty_objects_flag_set=false
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=false
22 = output_template_name_specified=false
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=false
25 = boolean_columns_specified=false
26 = numeric_columns_specified=false
27 = output_redirected=to_file
28 = record_field_data=only_ascii
```


-------------------------------------

### Configuration #11: ###


```sh
1 = input_file_type=multiple
2 = input_file_size=large
3 = csv_syntax_is_valid=true
4 = records_contain_same_number_of_fields=true
5 = record_contains_trailing_comma=true
6 = record_field_contains_space=true
7 = record_field_escaped=true
8 = record_field_contains_comma=true
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=true
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=true
13 = contents_contain_empty_strings=true
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=true
17 = contents_empty=false
18 = arrays_flag_set=false
19 = remove_empty_objects_flag_set=false
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=false
22 = output_template_name_specified=false
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=false
25 = boolean_columns_specified=true
26 = numeric_columns_specified=true
27 = output_redirected=to_command
28 = record_field_data=only_non_ascii
```


-------------------------------------

### Configuration #12: ###


```sh
1 = input_file_type=multiple
2 = input_file_size=none
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=true
18 = arrays_flag_set=true
19 = remove_empty_objects_flag_set=false
20 = remove_empty_strings_flag_set=true
21 = output_directory_specified=true
22 = output_template_name_specified=true
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=true
25 = boolean_columns_specified=false
26 = numeric_columns_specified=false
27 = output_redirected=to_standard_output
28 = record_field_data=only_ascii
```


-------------------------------------

### Configuration #13: ###


```sh
1 = input_file_type=directory
2 = input_file_size=small
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=false
18 = arrays_flag_set=true
19 = remove_empty_objects_flag_set=true
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=true
22 = output_template_name_specified=true
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=true
25 = boolean_columns_specified=true
26 = numeric_columns_specified=true
27 = output_redirected=to_file
28 = record_field_data=only_non_ascii
```


-------------------------------------

### Configuration #14: ###


```sh
1 = input_file_type=directory
2 = input_file_size=medium
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=false
18 = arrays_flag_set=false
19 = remove_empty_objects_flag_set=false
20 = remove_empty_strings_flag_set=true
21 = output_directory_specified=false
22 = output_template_name_specified=false
23 = dimensional_separator_specified=false
24 = delimiter_character_specified=false
25 = boolean_columns_specified=false
26 = numeric_columns_specified=false
27 = output_redirected=to_command
28 = record_field_data=contains_both
```


-------------------------------------

### Configuration #15: ###


```sh
1 = input_file_type=directory
2 = input_file_size=large
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=false
18 = arrays_flag_set=false
19 = remove_empty_objects_flag_set=true
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=true
22 = output_template_name_specified=true
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=false
25 = boolean_columns_specified=false
26 = numeric_columns_specified=true
27 = output_redirected=to_standard_output
28 = record_field_data=only_ascii
```


-------------------------------------

### Configuration #16: ###


```sh
1 = input_file_type=directory
2 = input_file_size=none
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=true
18 = arrays_flag_set=true
19 = remove_empty_objects_flag_set=true
20 = remove_empty_strings_flag_set=true
21 = output_directory_specified=true
22 = output_template_name_specified=true
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=false
25 = boolean_columns_specified=true
26 = numeric_columns_specified=false
27 = output_redirected=to_command
28 = record_field_data=only_non_ascii
```


-------------------------------------

### Configuration #17: ###


```sh
1 = input_file_type=non_existent
2 = input_file_size=none
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=true
18 = arrays_flag_set=true
19 = remove_empty_objects_flag_set=true
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=true
22 = output_template_name_specified=true
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=true
25 = boolean_columns_specified=true
26 = numeric_columns_specified=true
27 = output_redirected=to_file
28 = record_field_data=only_non_ascii
```


-------------------------------------

### Configuration #18: ###


```sh
1 = input_file_type=non_existent
2 = input_file_size=none
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=true
18 = arrays_flag_set=false
19 = remove_empty_objects_flag_set=false
20 = remove_empty_strings_flag_set=true
21 = output_directory_specified=false
22 = output_template_name_specified=false
23 = dimensional_separator_specified=false
24 = delimiter_character_specified=false
25 = boolean_columns_specified=false
26 = numeric_columns_specified=false
27 = output_redirected=to_standard_output
28 = record_field_data=contains_both
```


-------------------------------------

### Configuration #19: ###


```sh
1 = input_file_type=non_existent
2 = input_file_size=none
3 = csv_syntax_is_valid=false
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=false
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=false
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=true
18 = arrays_flag_set=true
19 = remove_empty_objects_flag_set=false
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=true
22 = output_template_name_specified=true
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=true
25 = boolean_columns_specified=false
26 = numeric_columns_specified=false
27 = output_redirected=to_command
28 = record_field_data=only_ascii
```


-------------------------------------

### Configuration #20: ###


```sh
1 = input_file_type=multiple
2 = input_file_size=small
3 = csv_syntax_is_valid=true
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=true
6 = record_field_contains_space=true
7 = record_field_escaped=true
8 = record_field_contains_comma=true
9 = record_field_contains_new_line=true
10 = record_field_contains_double_quotes=true
11 = contents_contain_arrays=true
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=true
15 = delimited_by_specified_character=true
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=false
18 = arrays_flag_set=false
19 = remove_empty_objects_flag_set=true
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=false
22 = output_template_name_specified=true
23 = dimensional_separator_specified=false
24 = delimiter_character_specified=true
25 = boolean_columns_specified=false
26 = numeric_columns_specified=false
27 = output_redirected=to_file
28 = record_field_data=only_ascii
```


-------------------------------------

### Configuration #21: ###


```sh
1 = input_file_type=plaintext
2 = input_file_size=large
3 = csv_syntax_is_valid=true
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=true
7 = record_field_escaped=true
8 = record_field_contains_comma=true
9 = record_field_contains_new_line=true
10 = record_field_contains_double_quotes=true
11 = contents_contain_arrays=true
12 = contents_contain_empty_objects=true
13 = contents_contain_empty_strings=true
14 = contents_contain_nested_objects=true
15 = delimited_by_specified_character=true
16 = dimensionally_separated_by_specified_character=true
17 = contents_empty=false
18 = arrays_flag_set=true
19 = remove_empty_objects_flag_set=true
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=true
22 = output_template_name_specified=false
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=true
25 = boolean_columns_specified=false
26 = numeric_columns_specified=false
27 = output_redirected=to_standard_output
28 = record_field_data=only_non_ascii
```


-------------------------------------

### Configuration #22: ###


```sh
1 = input_file_type=plaintext
2 = input_file_size=small
3 = csv_syntax_is_valid=true
4 = records_contain_same_number_of_fields=true
5 = record_contains_trailing_comma=true
6 = record_field_contains_space=true
7 = record_field_escaped=false
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=false
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=true
13 = contents_contain_empty_strings=true
14 = contents_contain_nested_objects=true
15 = delimited_by_specified_character=true
16 = dimensionally_separated_by_specified_character=true
17 = contents_empty=false
18 = arrays_flag_set=true
19 = remove_empty_objects_flag_set=false
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=false
22 = output_template_name_specified=false
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=true
25 = boolean_columns_specified=true
26 = numeric_columns_specified=false
27 = output_redirected=to_file
28 = record_field_data=only_ascii
```


-------------------------------------

### Configuration #23: ###


```sh
1 = input_file_type=plaintext
2 = input_file_size=medium
3 = csv_syntax_is_valid=true
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=true
6 = record_field_contains_space=false
7 = record_field_escaped=true
8 = record_field_contains_comma=true
9 = record_field_contains_new_line=true
10 = record_field_contains_double_quotes=true
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=true
13 = contents_contain_empty_strings=false
14 = contents_contain_nested_objects=true
15 = delimited_by_specified_character=true
16 = dimensionally_separated_by_specified_character=true
17 = contents_empty=false
18 = arrays_flag_set=true
19 = remove_empty_objects_flag_set=true
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=false
22 = output_template_name_specified=true
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=true
25 = boolean_columns_specified=true
26 = numeric_columns_specified=false
27 = output_redirected=to_file
28 = record_field_data=only_ascii
```


-------------------------------------

### Configuration #24: ###


```sh
1 = input_file_type=multiple
2 = input_file_size=small
3 = csv_syntax_is_valid=true
4 = records_contain_same_number_of_fields=false
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=true
7 = record_field_escaped=true
8 = record_field_contains_comma=false
9 = record_field_contains_new_line=true
10 = record_field_contains_double_quotes=true
11 = contents_contain_arrays=false
12 = contents_contain_empty_objects=false
13 = contents_contain_empty_strings=true
14 = contents_contain_nested_objects=true
15 = delimited_by_specified_character=false
16 = dimensionally_separated_by_specified_character=true
17 = contents_empty=false
18 = arrays_flag_set=false
19 = remove_empty_objects_flag_set=true
20 = remove_empty_strings_flag_set=false
21 = output_directory_specified=false
22 = output_template_name_specified=true
23 = dimensional_separator_specified=true
24 = delimiter_character_specified=false
25 = boolean_columns_specified=false
26 = numeric_columns_specified=true
27 = output_redirected=to_standard_output
28 = record_field_data=only_ascii
```


-------------------------------------

### Configuration #25: ###


```sh
1 = input_file_type=plaintext
2 = input_file_size=large
3 = csv_syntax_is_valid=true
4 = records_contain_same_number_of_fields=true
5 = record_contains_trailing_comma=false
6 = record_field_contains_space=true
7 = record_field_escaped=true
8 = record_field_contains_comma=true
9 = record_field_contains_new_line=true
10 = record_field_contains_double_quotes=false
11 = contents_contain_arrays=true
12 = contents_contain_empty_objects=true
13 = contents_contain_empty_strings=true
14 = contents_contain_nested_objects=true
15 = delimited_by_specified_character=true
16 = dimensionally_separated_by_specified_character=false
17 = contents_empty=false
18 = arrays_flag_set=false
19 = remove_empty_objects_flag_set=true
20 = remove_empty_strings_flag_set=true
21 = output_directory_specified=false
22 = output_template_name_specified=true
23 = dimensional_separator_specified=false
24 = delimiter_character_specified=true
25 = boolean_columns_specified=false
26 = numeric_columns_specified=false
27 = output_redirected=to_command
28 = record_field_data=contains_both
```


-------------------------------------