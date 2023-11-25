#pragma once
#include "Common.h"
#include "Config.h"
#include "Event.h"

namespace StrippingArmor
{
	void                MainLoop();
	int                 GetStrippingArmorIndex();
	RE::BGSKeyword*     GetKeywordFromID(int formID);
	RE::TESBoundObject* GetArmorFromID(int formID);
	void                ResetParameter();
	void                UpdateCrosshairTarget();
	void                StateSelector();
	bool                IsTargetValid(bool isLastTarget);
	bool                IsTargetDead(bool isLastTarget);
	void                State_Common(bool targetOn, bool crosshairOn);
	void                State_Dialogue();
	void                StateTargetOffCrosshairOff();
	void                StateTargetOnCrosshairOff_CommonRoute();
	void                StateTargetOnCrosshairOff_LivingRoute();
	void                StateTargetOnCrosshairOn_LivingRoute();
	void                StateTargetOffCrosshairOn_Common();
	void                StateTargetOffCrosshairOn_LivingRoute();
	bool                IsTapped();
	bool                IsReady();
	bool                IsLooted();
	void                StateTargetOnCrosshairOff_CorpseRoute();
	void                StateTargetOnCrosshairOn_CorpseRoute();
	void                LootAndRemove();
	void                StateTargetOffCrosshairOn_CorpseRoute();
	void                MemberChecker();
	bool                MCHasKeyword(RE::TESObjectREFR* object, std::string keywordString);
	void                MemberCheckerCandidate();
	void                MemberCheckerCorpse();
	void                AddKeywordForCandidates(RE::TESObjectREFR* member, bool byKey);
	void                AddKeywordForCorpses(RE::TESObjectREFR* member);
	bool                IsReady(RE::TESObjectREFR* member);
	bool                IsReadyForCorpse(RE::TESObjectREFR* member);
	bool                CheckByKey(RE::TESObjectREFR* member);
	bool                IsBreathable(RE::TESObjectREFR* member);
	bool                ShouldShowSpaceSuit(RE::TESObjectREFR* member);
	bool                CheckConditionOK(RE::TESObjectREFR* member);
	void                StrippingArmorWithKeyword(RE::TESObjectREFR* member);
	int                 GetHighOrLow(RE::TESObjectREFR* member);
	void                ChangingCorpseWithKeyword(RE::TESObjectREFR* member);
	void                RemoveCandidateKeywords(RE::TESObjectREFR* member);
	void                RemoveCorpseKeywords(RE::TESObjectREFR* member);
	void                DropEquipItems();
	void                RemoveEquipItems(bool leftOne);
	bool                NeedDummysuit(RE::TESObjectREFR* member);
	void                EquipDummysuit(RE::TESObjectREFR* member);
	void                DoEffectShader(RE::TESObjectREFR* member);
	RE::TESBoundObject* GetCorpsesuit(RE::TESObjectREFR* member);
	int                 GetArmorClothCombination();
	bool                IsKeyPressed();
	void                ChangingCorpse2(RE::TESObjectREFR* targetActor, int HighOrLow);
	RE::TESBoundObject* GetArmor(std::string editorID);
	RE::BGSKeyword*     GetKeyword(std::string editorID);
	void                MakeKeywordMapIfNeeded();
	void                MakeArmorMapIfNeeded();


	inline int                                                  StrippingArmorIndex = 0;
	inline int                                                  FormIDForModIndex = 0x827;
	inline std::string                                          NameForModIndex = "SACandidateCheckReady";
	inline std::unordered_map<std::string, RE::BGSKeyword*>     KeywordMap;
	inline std::unordered_map<std::string, RE::TESBoundObject*> ArmorMap;
	inline bool                                                 EffectON = false;
	inline bool                                                 NeedReset = false;
	inline RE::TESObjectREFR*                                   target;
	inline RE::TESObjectREFR*                                   LastTarget;
	inline bool                                                 crosshairrefOn = false;
	inline int                                                  RepickTimer = 5;
	inline std::unordered_map<RE::TESObjectREFR*, bool>         Candidates;
	inline std::unordered_map<RE::TESObjectREFR*, bool>         Corpses;
	inline int                                                  WaitCount = 0;
	inline int                                                  WaitCountPlus = 10;
	inline std::unordered_map<RE::TESBoundObject*, std::string> ArmorTypesMap;
	inline std::unordered_map<RE::TESObjectREFR*, bool>         ReadyStateMap;
	inline std::unordered_map<RE::TESObjectREFR*, int>          ArmorClothCombinationMap;
	inline std::unordered_map<RE::TESObjectREFR*, bool>         LootedCorpseMap;
	inline std::unordered_map<RE::TESObjectREFR*, bool>         StrippingKeyTappedMap;
}