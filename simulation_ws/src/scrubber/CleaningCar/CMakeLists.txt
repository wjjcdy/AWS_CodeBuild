cmake_minimum_required(VERSION 2.8.3)

project(CleaningCar)

find_package(catkin REQUIRED COMPONENTS
   gazebo_ros)

catkin_package(DEPENDS gazebo_ros)

find_package(roslaunch)

foreach(dir config launch meshes urdf)
	install(DIRECTORY ${dir}/
		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
