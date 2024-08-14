cmake_minimum_required(VERSION 3.16)

project(LogicQt LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(LogicQt
  main.cpp
  Build.cpp Build.h Definition.cpp Definition.h Game.cpp Game.h Global.cpp Global.h Lists.cpp Lists.h Trie.cpp Trie.h VietNamese.cpp VietNamese.h Word.cpp Word.h
)
target_link_libraries(LogicQt Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS LogicQt
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
