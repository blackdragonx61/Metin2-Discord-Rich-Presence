///Add
#if defined(ENABLE_DISCORD_RPC)
#include "discord_rpc.h"
#ifdef _DEBUG
#pragma comment(lib, "discord_rpc_d.lib")
#else
#pragma comment(lib, "discord_rpc_r.lib")
#endif
static int64_t StartTime;
static constexpr auto DiscordClientID = "667352913621942276"; //Change
void CPythonNetworkStream::Discord_Start()
{
	StartTime = time(0);
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	Discord_Initialize(DiscordClientID, &handlers, 1, nullptr);
	Discord_Update(false);
}
void CPythonNetworkStream::Discord_Update(const bool ingame)
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	if (ingame) {
		discordPresence.state = CPythonBackground::Instance().GetWarpMapName();
		discordPresence.details = CPythonPlayer::Instance().GetName();
	}
	discordPresence.startTimestamp = StartTime;
	discordPresence.largeImageKey = "image1";
	discordPresence.largeImageText = "Metin2";
	Discord_UpdatePresence(&discordPresence);
}
void CPythonNetworkStream::Discord_Close()
{
	Discord_Shutdown();
}
#endif