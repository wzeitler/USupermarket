// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <utility>
#include "Components/ActorComponent.h"
#include "CPlaceItem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLACINGOBJECTS_API UCPlaceItem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPlaceItem();

	UPROPERTY(EditAnywhere)
		AActor* Item;

	UPROPERTY(EditAnywhere)
		float RaycastRange;

	// The spacing along the X-axis
	UPROPERTY(EditAnywhere)
	float fSpacingX;

	// The spacing along the Y-axis
	UPROPERTY(EditAnywhere)
		float fSpacingY;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	ACharacter* Character;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* RedMaterial;

	UPROPERTY()
		UMaterialInterface* ItemMaterial;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	std::pair<FHitResult, bool> StartRaytrace();

	// Inreases or decreases the space between the items
	void ChangeSpacing(const float Val);

	// Places the items as shown by the phantom items
	void PlaceItems();


	// *** Deprecated*** Places a single item
	void PlaceSingleItem();

	// *** Deprecated*** Places a row of items
	void PlaceRowItems();

	// *** Deprecated*** Places items to fill the available space
	void FillItems();

private:

	//**** UI TextmessageIDs
	int iTextID_XSpacing = 1;
	int iTextID_YSpacing = 2;
	int iTextID_SpacingStep = 3;
	int iTextID_Error = 4;
	//**********************

	FVector LocationToPlaceItem;

	bool bItemCanBePlaced;

	std::pair<FHitResult, bool> RaytraceResults;

	float fSpacingStep;

	UPROPERTY()
	TArray<AActor*> PhantomItems;
	
	// Displays the phantom item at a position where the raytrace hit the shelf
	void DisplayPhantomItem(FHitResult Hit);

	// Helper function to get the static mesh from an actor
	UStaticMeshComponent* GetStaticMesh(AActor* Actor);

	// Increases the steps for spacing the items
	void IncreaseSpacingStep();

	// Decreases the steps for spacing the items
	void DecreaseSpacingStep();



	// *** Deprecated***Helper function: Places an item to a specific position
	void PlaceItemAtPosition(FVector Position);
};
