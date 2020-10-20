 
 set(Flat "32")

 if(Flat EQUAL "32")
 	set(SupplyOpencv_DIR "D:/vs_nty/OPENCV_SUPPLY_32BIT")
 	set(SupplyOpencv_Include_Dirs  "D:/vs_nty/OPENCV_SUPPLY_32BIT")
 	set(SupplyOpencv_Libs "D:/vs_nty/OPENCV_SUPPLY_32BIT")
 elseif(Flat MATCHES "^[0-9]{2}$")
 	message("there are no 63lib")
 endif()


