phone_list(person('Mitul', 'Chavda'), '8155884321', bdate(day(05),month(04),year(2001))).
phone_list(person('Yug', 'Dave'), '47079889273', bdate(day(20),month(07),year(2002))).
phone_list(person('Dhruv','Ambaliya'), '2479374897', bdate(day(03),month(02),year(2002))).
phone_list(person('Krish','Patel'),'9872437347'bdate(day(15),month(08),year(2002))).
phone_list(person('Sachin','Solanki'),'4582784970',bdate(day(08),month(08),year(2002))).
phone_list(person('Raj','Patel'),'9872437347',bdate(day(15),month(08),year(2002))).

query(X) :- phone_list(person(A,_),B,bdate(day(_),month(X),year(_))), write(A), write(' '), write(B).

