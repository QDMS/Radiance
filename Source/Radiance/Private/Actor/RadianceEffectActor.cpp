// Copyright TPGames


#include "Actor/RadianceEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/RadianceAttributeSet.h"
#include "Components/SphereComponent.h"


ARadianceEffectActor::ARadianceEffectActor()
{
 
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
	

}

void ARadianceEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const URadianceAttributeSet* RadianceAttributeSet = Cast<URadianceAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(URadianceAttributeSet::StaticClass()));
		URadianceAttributeSet* MutableRadianceAttributeSet = const_cast<URadianceAttributeSet*>(RadianceAttributeSet);
		MutableRadianceAttributeSet->SetHealth(RadianceAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
	
}

void ARadianceEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ARadianceEffectActor::BeginPlay()
{
	Super::BeginPlay(); 

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ARadianceEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ARadianceEffectActor::EndOverlap);
}

