rm -f results
echo "TESTS" >> results
echo "BUFF 2048" >> results
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2048 get_next_line.c get_next_line_utils.c main.c
./a.out < tests/z_longmulti >> results
echo >> results
echo >> results
echo "BUFF 2" >> results
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c main.c
./a.out < tests/z_longmulti >> results
echo >> results
echo >> results
echo "BUFF 1" >> results
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c
./a.out < tests/z_longmulti >> results
echo >> results
echo >> results
echo "BUFF 4" >> results
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=4 get_next_line.c get_next_line_utils.c main.c
./a.out < tests/z_longmulti >> results
echo >> results
echo >> results
echo "BUFF 3" >> results
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=3 get_next_line.c get_next_line_utils.c main.c
./a.out < tests/z_longmulti >> results
echo >> results
echo >> results
echo "BUFF 5" >> results
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c main.c
./a.out < tests/z_longmulti >> results
echo >> results
echo >> results
