// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class AHexTile;

/**
 * 
 */
class BIGLITTLEPLANET_API HexNode
{
public:
	HexNode();
	~HexNode();

	TArray<HexNode*> adjacentNodes;

	AHexTile* selectedTile;

	int rotationsClockwise = 0;
	
	TArray<AHexTile*> availableTileOptions;

};
