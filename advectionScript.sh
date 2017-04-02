for i in {10..10000..10}
do
    for j in {50..5000000..1000}
    do
   	./advection data/dataset1.vtk $i*.000001 $j >"output$i$j"
   	time ./advection data/dataset1.vtk $i*.000001 $j >"time$i$j"
         
    done
done
