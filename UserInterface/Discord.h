/*
* blackdragonx61
* Mali
*/

#pragma once
#include "StdAfx.h"
#include "PythonCharacterManager.h"
#include "PythonBackground.h"
#include "PythonPlayer.h"
#include "PythonGuild.h"

namespace Discord
{
	constexpr auto DiscordClientID = "667352913621942276";

	using DCDATA = std::pair<std::string, std::string>;

	/*NAME*/
	inline DCDATA GetNameData()
	{
		/*Map Name*/
		auto WarpName = std::string(CPythonBackground::Instance().GetWarpMapName());

		//atlasinfo.txt
		static const std::map<std::string, std::string> m_MapName {
			{ "metin2_map_a1", "Yongan" },
			{ "metin2_map_b1", "Joan" },
			{ "metin2_map_c1", "Pyungmoo" },
		};

		auto sMapName = "Location: " + (m_MapName.count(WarpName) ? m_MapName.at(WarpName) : WarpName);

		/*CH Name*/
		auto sCharacterName = "Name: " + std::string(CPythonPlayer::Instance().GetName());
#if 0
		std::string GuildName;
		if (CPythonGuild::Instance().GetGuildName(CPythonPlayer::Instance().GetGuildID(), &GuildName))
			sCharacterName += "-Guild: " + GuildName;
#else
		sCharacterName += " (Lv." + std::to_string(CPythonPlayer::Instance().GetStatus(POINT_LEVEL)) + ")";
#endif

		return { sMapName, sCharacterName };
	}

	/*RACE*/
	inline DCDATA GetRaceData()
	{
		auto pInstance = CPythonCharacterManager::Instance().GetMainInstancePtr();
		if (!pInstance)
			return { "","" };

		/*Race*/
		const auto RACENUM = pInstance->GetRace();
		
		/*Image*/
		auto RaceImage = "race_" + std::to_string(RACENUM);

		/*Name*/
		auto RaceName = "";
		switch (RACENUM)
		{
		case NRaceData::JOB_WARRIOR:
		case NRaceData::JOB_WARRIOR + 4:
			RaceName = "Warrior";
			break;
		case NRaceData::JOB_ASSASSIN:
		case NRaceData::JOB_ASSASSIN + 4:
			RaceName = "Assassin";
			break;
		case NRaceData::JOB_SURA:
		case NRaceData::JOB_SURA + 4:
			RaceName = "Sura";
			break;
		case NRaceData::JOB_SHAMAN:
		case NRaceData::JOB_SHAMAN + 4:
			RaceName = "Shaman";
			break;
#if defined(ENABLE_WOLFMAN_CHARACTER)
		case NRaceData::JOB_WOLFMAN + 4:
			RaceName = "Lycan";
#endif
		}
		return { RaceImage , RaceName };
	}

	/*EMPIRE*/
	inline DCDATA GetEmpireData()
	{
		auto pInstance = CPythonCharacterManager::Instance().GetMainInstancePtr();
		if (!pInstance)
			return { "","" };

		const auto EmpireID = pInstance->GetEmpireID();

		/*Image*/
		auto EmpireImage = "empire_" + std::to_string(EmpireID);

		/*Name*/
		auto EmpireName = "";
		switch (EmpireID)
		{
		case 1:
			EmpireName = "Shinsoo";
			break;
		case 2:
			EmpireName = "Chunjo";
			break;
		case 3:
			EmpireName = "Jinno";
		}
		return { EmpireImage, EmpireName};
	}
}
