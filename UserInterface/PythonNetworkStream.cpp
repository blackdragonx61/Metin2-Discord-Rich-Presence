//Find
			SetSelectPhase();
			
///Add
#if defined(ENABLE_DISCORD_RPC)
			Discord_Update(false);
#endif

//Find
			SetGamePhase();
			
///Add
#if defined(ENABLE_DISCORD_RPC)
			Discord_Update(true);
#endif

//Find
	Tracen("## Network - OffLine Phase ##");
	
///Add
#if defined(ENABLE_DISCORD_RPC)
	Discord_Update(false);
#endif