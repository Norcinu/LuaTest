//
//  main.cpp
//  LuaTest
//
//  Created by Steven Gleed on 23/10/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#include <iostream>
#include <lua.hpp>
#include <unistd.h>

int main(int argc, const char * argv[])
{
	lua_State *l = lua_open();
	luaL_openlibs(l);
	
	int s = luaL_loadfile(l, "/Users/Steven/Documents/code/LuaTest/test.lua");
	if ( s == 0) {
		s = lua_pcall(l, 0, LUA_MULTRET, 0);
		std::cout << "Reading variable from lua ";
		lua_getglobal(l, "luavar");
		int r = lua_tonumber(l, -1);
		std::cout << r << std::endl;
		while(true) {
			s = luaL_loadfile(l, "/Users/Steven/Documents/code/LuaTest/test.lua");
			s = lua_pcall(l, 0, LUA_MULTRET, 0);
			std::cout << "Reading variable from lua ";
			lua_getglobal(l, "luavar");
			int r = lua_tonumber(l, -1);
			lua_pop(l,1);
			std::cout << r << std::endl;
			usleep(100000);
		}
	}
	else if (s != 0) {
		std::cerr << lua_tostring(l, -1) << std::endl;
		lua_pop(l, 1);
	}
	
	
	
	lua_close(l);
}

