#include "artery/envmod/CarIdentityRegistrant.h"
#include "artery/utility/IdentityRegistry.h"
#include "artery/traci/VehicleMobility.h"
#include "inet/common/ModuleAccess.h"


namespace artery
{

Define_Module(CarIdentityRegistrant)

void CarIdentityRegistrant::initialize()
{
	initializeIdentity();
	registerIdentity();
}

void CarIdentityRegistrant::initializeIdentity()
{
	auto parent = this->getParentModule();
	auto mobility = dynamic_cast<VehicleMobility*>(parent->getSubmodule("mobility"));
	if (!mobility) {
		throw omnetpp::cRuntimeError("no suitable mobility module found");
	}

	mIdentity.host = parent;
	mIdentity.application = Identity::deriveStationId(parent, par("stationIdDerivation").stringValue());
	mIdentity.traci = mobility->getVehicleController()->getVehicleId();
}

void CarIdentityRegistrant::registerIdentity()
{
	emit(artery::IdentityRegistry::updateSignal, &mIdentity);
}

void CarIdentityRegistrant::finish()
{
	emit(artery::IdentityRegistry::removeSignal, &mIdentity);
}

} // namespace artery
