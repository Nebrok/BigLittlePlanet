// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HexTile.h"
#include "CoreMinimal.h"

/**
 * 
 */
class BIGLITTLEPLANET_API HexNode
{
public:
	HexNode();
	~HexNode();

	TArray<HexNode*> adjacentNodes[6];

	AHexTile* selectedTile;
	int rotationsClockwise = 0;
	TArray<AHexTile*> availableTileOptions;

};
