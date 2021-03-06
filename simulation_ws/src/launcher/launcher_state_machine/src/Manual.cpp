//*********************************************************
//
// Copyright (c) 2019 Roborock. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

#include "launcher_state_machine/Manual.h"

namespace rock::scrubber::launcher {
	Manual::Manual(std::shared_ptr<rock::scrubber::launcher::ScrubberStates>& states) {
		states_ = states;
		report_ = std::make_unique<Report>();
		states_->shiftState(States::MANUAL);
		report_ -> start();
	}

	void Manual::pause() {
		states_->shiftState(States::PAUSE);
	}

	void Manual::resume() {
		states_->shiftState(states_->getLastState());
	}

	void Manual::cancel() {
		Mission::cancel();
		done_ = true;
		success_ = true;
		states_->shiftState(States::IDLE);
		ROS_INFO("Clean time: %d", report_->getCleanTime());
	}

	void Manual::start() {

	}
}