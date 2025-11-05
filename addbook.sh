echo "Enter File Name:"
read fname
repeat=1
while [ $repeat -eq 1 ]
do
echo -e "\n1.Create File \n2.Add Record \n 3.Display Record \n4.Search Record \n5.Delete Record \n Enter your choice: "
read ch

case $ch in
1)
	touch $fname
	echo -e "EmpId\tName\tCity\tMob">>$fname
	;;
	
2)
	echo "Enter EmpID: "
	read id
	echo "Enter Name: "
	read name
	echo "Enter City: "
	read city
	echo "Mob: "
	read mob
	
	echo -e "$id\t$name\t$city\t$mob">>$fname
	;;
	
3)
	cat $fname
	;;
	
4)
	echo -e "Enter EmpId to Search"
	read id
	
	if grep $id $fname
	then
		echo -e "ID found"
	else
		echo -e "not found"
	fi
	;;
5)
	echo -e "Enter EmpId to Delete"
	read id
	if grep $id $fname
	then
		sed -i "/$id/d" $fname
		echo -e "Record Deleted"
	else
		echo -e "Record not found"
	fi
	;;
esac
echo -e "Do you want to continue ?(1/0)"
read repeat
done
	
