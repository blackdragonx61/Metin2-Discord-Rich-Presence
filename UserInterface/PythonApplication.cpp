//Find
	if (m_pySystem.IsUseDefaultIME())
	{
		CPythonIME::Instance().UseDefaultIME();
	}
	
///Add
#if defined(ENABLE_DISCORD_RPC)
	m_pyNetworkStream.Discord_Start();
#endif

//Find
	m_pyGraphic.Destroy();
	
///Add
#if defined(ENABLE_DISCORD_RPC)
	m_pyNetworkStream.Discord_Close();
#endif