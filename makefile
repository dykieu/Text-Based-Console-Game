OBJS = main.o menu.o inputVal.o game.o item.o boss.o orc.o object.o rm_Trap.o rm_Boss.o mBoss.o rm_MBoss.o rm_Blood.o rm_TH.o rm_Armory.o rm_Barrack.o rm_Garden.o rat.o rm_Hide.o rm_Base.o rm_Hallway.o character.o hunter.o dice.o space.o rm_Empty.o map.o
SRC = main.cpp menu.cpp inputVal.cpp game.cpp item.cpp rm_Boss.cpp rm_Trap.cpp boss.cpp orc.ccp mBoss.cpp rm_MBoss.cpp rm_Blood.cpp rm_TH.cpp rm_Armory.cpp rm_Barrack.cpp rm_Garden.cpp object.cpp rm_Hide.cpp rat.cpp rm_Base.cpp rm_Hallway.cpp character.cpp hunter.cpp dice.cpp rm_Empty.cpp map.cpp
HEADERS = menu.hpp inputVal.hpp game.hpp orc.hpp item.hpp rm_Boss.hpp rm_Trap.hpp boss.hpp object.hpp mBoss.hpp rm_MBoss.hpp rm_Blood.hpp rm_TH.hpp rm_Armory.hpp rm_Barrack.hpp rm_Garden.hpp rm_Hide.hpp rat.hpp rm_Base.hpp rm_Hallway.hpp character.hpp hunter.hpp dice.hpp rm_Empty.hpp map.hpp

lab: ${OBJS} ${HEADERS}
	 g++ -g -std=c++11 ${OBJS} -o proj
OBJS: ${SRC}
	g++ -c $(@:.o=cpp) ${SRC}
clean:
	rm *.o proj

