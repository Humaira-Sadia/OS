echo "Enter the number : "
read number

for ((i=2;i<=$number;i++)); do
    flag=1
    for ((j=2;j<=i/2;j++)); do
        if [ $((i%j)) -eq 0 ]; then
            flag=0
            break
        fi
    done
    
    if [ $flag -eq 1 ]; then
        echo -n "$i "
    fi
done
echo ""
