
from gggg import *

a = Assignment(21, 10)
s = State(a)

horizontal_rule()

s.reject_if_missing_contributors()
s.reject_if_starter_contributors()

s.reject_unless_files_exist(['Book.hpp',
                             'Book.cpp',
                             'Book_test.cpp'])

s.reject_if_file_unchanged('Book.cpp',
                           '953ed73434f4cae54b9161b48da2f25a2622522198a655c00de571bb596b16df')

s.reject_if_file_changed('Book_test.cpp',
                         'af6b36ea94ec8262e247376affa66f3821cf5b92fb295f93c6cc71c1f8e19eed')

s.reject_unless_command_succeeds(['make', 'clean', 'test'])

s.string_removed_test('TO-DO comments removed', 3, 'TO-DO', ['Book.cpp'])

s.gtest_run('Book_test')
s.gtest_suite_test('ConstructorsAndAssignment', 3)
s.gtest_suite_test('Accessors', 3)
s.gtest_suite_test('Modifiers', 3)
s.gtest_suite_test('RelationalOperators', 3)
s.gtest_suite_test('StreamInsertion', 3)
s.gtest_suite_test('StreamExtraction', 3)

s.summarize()
