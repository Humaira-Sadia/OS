echo "Enter the number : ";
read number;
i=$number;
p=1;
while [ $i -ge 1 ]; do
    p=$(expr $p \* $i)
    i=$(expr $i - 1)
done
echo "The Factorial of given number is : $p"
