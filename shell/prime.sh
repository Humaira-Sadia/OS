echo "Enter the number : "
read number

i=2
while [ $i -le $((number/2)) ]; do
    if [ $((number%i)) -eq 0 ]; then
        echo "$number is not a Prime Number."
        exit 0;
    fi
    i=$((i+1))
done
echo "$number is a Prime Number."
