// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetData.h"

PlanetData::PlanetData(int distance, int ironResource, int woodResource, int dangerRating0to100, int richRating0to100)
{
	distanceToUsLightyears = distance;

	ironOnPlanet = ironResource;

	woodOnPlanet = woodResource;

	dangerRating = dangerRating0to100;

	richesRating = richRating0to100;

}

PlanetData::~PlanetData()
{
}


