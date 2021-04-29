nasm -f elf32 -o myGCM.o myGCM.asm
gcc -m32 -g myGCM.o -o myGCM

#read output < ./labp1 <<< '10 5' | sed -n 2p
#(echo "10 5" | ./labp1) > validation.txt
#output=$(./myGCM <<< '10 5')
#echo $output
#expected_output="El GCM de 10 y 5 es: 5"
#if [ "$output" == "$expected_output" ] ; then
#  echo "Pass: Output is correct"
#else
#  echo "Expected '$expected_output' but got: $output"
#  exit 1
#fi

./myGCM <<< '10 5'

./myGCM <<< '150 100'

./myGCM <<< '15 10'

