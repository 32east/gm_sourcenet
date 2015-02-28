#pragma once

#include <GarrysMod/Lua/Interface.h>
#include <cstdint>
#include <new>

extern "C"
{

#include <lua.h>

}

#if defined __linux || defined __APPLE__

#undef min
#undef max

#endif

class IVEngineServer;
class IVEngineClient;
class IServer;
class QAngle;
class Vector;

namespace Global
{

#if defined _WIN32

static const char *engine_lib = "engine.dll";
static const char *client_lib = "client.dll";
static const char *server_lib = "server.dll";

#elif defined __linux

#if defined SOURCENET_SERVER

static const char *engine_lib = "bin/engine_srv.so";
static const char *server_lib = "garrysmod/bin/server_srv.so";

#elif defined SOURCENET_CLIENT

static const char *engine_lib = "bin/engine.so";
static const char *server_lib = "garrysmod/bin/server.so";

#endif

static const char *client_lib = "garrysmod/bin/client.so";

#elif defined __APPLE__

static const char *engine_lib = "engine.dylib";
static const char *client_lib = "client.dylib";
static const char *server_lib = "server.dylib";

#endif

static const uint8_t metabase = 100;

extern lua_State *lua_state;

extern void *( *engine_factory )( const char *pName, int *pReturnCode );

extern IVEngineServer *engine_server;

extern IVEngineClient *engine_client;

extern IServer *server;

LUA_FUNCTION( index );
LUA_FUNCTION( newindex );
LUA_FUNCTION( GetTable );

void CheckType( lua_State *state, int32_t index, int32_t type, const char *nametype );

void ThrowError( lua_State *state, const char *fmt, ... );

void PushAngle( lua_State *state, const QAngle &ang );

void PushVector( lua_State *state, const Vector &vec );

}