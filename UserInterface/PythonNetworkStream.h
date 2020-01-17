//Find
		void SetWaitFlag();
		
///Add
#if defined(ENABLE_DISCORD_RPC)
		void Discord_Start();
		void Discord_Close();
		void Discord_Update(const bool ingame);
#endif