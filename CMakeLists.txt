cmake_minimum_required (VERSION 2.8.12)

project (TuringsMachineGenerator)

find_package (Qt5Widgets)

set (ProjectLib_src editmachines.cpp edittapes.cpp 
machine.cpp machinesimulation.cpp qrc_resource.cpp randommachines.cpp randomtapes.cpp 
settings.cpp tape.cpp usermachines.cpp)

set (ProjectLib_hdr editmachines.h edittapes.h 
machine.h machinesimulation.h randommachines.h randomtapes.h 
settings.h tape.h usermachines.h)

set (ProjectLib_ui editmachines.ui edittapes.ui 
machinesimulation.ui randommachines.ui randomtapes.ui 
settings.ui usermachines.ui)

set (ProjectBin_src main.cpp)

qt5_wrap_cpp(ProjectLib_hdr_moc ${ProjectLib_hdr})
qt5_wrap_ui (ProjectLib_ui_moc  ${ProjectLib_ui})

add_library (ProjectLib SHARED 
    ${ProjectLib_src}
    ${ProjectLib_hdr_moc}
    ${ProjectLib_ui_moc}
)
target_link_libraries (ProjectLib Qt5::Widgets)

add_executable(TuringsMachineGenerator ${ProjectBin_src})
target_link_libraries (TuringsMachineGenerator ProjectLib)