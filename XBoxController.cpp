#include <iostream>
#include <cmath>

#include "XBoxController.h"
#include "XInputWrapper.h"

using namespace std;

GamePad::XBoxController::XBoxController(XInputWrapper * xinput, DWORD id) {
	this->xinput = xinput;
	this->id = id;
	this->dead_zone = 0;
}

DWORD GamePad::XBoxController::GetControllerId() {
	return this->id;
}

bool GamePad::XBoxController::IsConnected() {
	return (this->xinput->XInputGetState(this->id, this->pState) != ERROR_DEVICE_NOT_CONNECTED);
}

bool GamePad::XBoxController::PressedA() {
	this->update_gamepad();
	return (this->pState->Gamepad->wButtons & XINPUT_GAMEPAD_A);
}

bool GamePad::XBoxController::PressedB() {
    this->update_gamepad();
    return (this->pState->Gamepad->wButtons & XINPUT_GAMEPAD_B);
} 

bool GamePad::XBoxController::PressedX() {
    this->update_gamepad();
    return (this->pState->Gamepad->wButtons & XINPUT_GAMEPAD_X);
}

bool GamePad::XBoxController::PressedY() {
    this->update_gamepad();
    return (this->pState->Gamepad->wButtons & XINPUT_GAMEPAD_Y);
}

bool GamePad::XBoxController::PressedLeftShoulder() {
    this->update_gamepad();
    return (this->pState->Gamepad->wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER);
}

bool GamePad::XBoxController::PressedRightShoulder() {
    this->update_gamepad();
    return (this->pState->Gamepad->wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER);
}

bool GamePad::XBoxController::PressedLeftDpad() {
    this->update_gamepad();
    return (this->pState->Gamepad->wButtons & XINPUT_GAMEPAD_DPAD_LEFT);
}

bool GamePad::XBoxController::PressedRightDpad() {
    this->update_gamepad();
    return (this->pstate->Gamepad->wbuttons & XINPUT_GAMEPAD_DPAD_RIGHT);
}

bool GamePad::XBoxController::PressedUpDpad() {
    this->update_gamepad();
    return (this->pstate->Gamepad->wbuttons & XINPUT_GAMEPAD_DPAD_UP);
}

bool GamePad::XBoxController::PressedDownDpad() {
    this->update_gamepad();
    return (this->pstate->Gamepad->wbuttons & XINPUT_GAMEPAD_DPAD_DOWN);
}

bool GamePad::xboxcontroller::PressedStart() {
    this->update_gamepad();
    return (this->pstate->Gamepad->wbuttons & XINPUT_GAMEPAD_START);
}

bool GamePad::XBoxController::PressedBack() {
    this->update_gamepad();
    return (this->pstate->Gamepad->wbuttons & XINPUT_GAMEPAD_BACK);
}

bool GamePad::XBoxController::PressedLeftThumb() {
    this->update_gamepad();
    return (this->pstate->Gamepad->wbuttons & XINPUT_GAMEPAD_LEFT_THUMB);
}

bool GamePad::XBoxController::PressedRightThumb() {
    this->update_gamepad();
    return (this->pstate->Gamepad->wbuttons & XINPUT_GAMEPAD_RIGHT_THUMB);
}

BYTE GamePad::XBoxController::LeftTriggerLocation() {
    this->update_gamepad();
    return this->pState->Gamepad->bLeftTrigger;
}

BYTE GamePad::XBoxController::RightTriggerLocation() {
    this->update_gamepad();
    return this->pState->Gamepad->bRightTrigger;
}

GamePad::Coordinate GamePad::XBoxController::LeftThumbLocation() {
    this->update_gamepad();
    SHORT lThumbStickx = this->pState->Gamepad->sThumbLX;
    SHORT lThumbSticky = this->pState->Gamepad->sThumbLY;
    if (pow(lThumbStickx, 2) + pow(lThumbSticky, 2) < pow(this->dead_zone, 2)) {
        return GamePad::Coordinate ret_coord(lThumbStickx, lThumbSticky);
    } else {
        return GamePad::Coordinate ret_coord(0,0);
    }
}

GamePad::Coordinate GamePad::XBoxController::RightThumbLocation() {
    this->update_gamepad();
    SHORT rThumbStickx = this->pState->Gamepad->sThumbRX;
    SHORT rThumbSticky = this->pState->Gamepad->sThumbRY;
    if (pow(rThumbStickx, 2) + pow(rThumbSticky, 2) < pow(this->dead_zone, 2)) {
        return GamePad::Coordinate ret_coord(rThumbStickx, rThumbSticky);
    } else {
        return GamePad::Coordinate ret_coord(0,0);
    }
}

void GamePad::XBoxController::Vibrate(WORD left, WORD right) {
    this->pVibration->wLeftMotorSpeed = left;
    this->pVibration->wRightMotorSpeed = Right;
    this->xinput->XInputSetState(this->id, this->pVibration);
}


void GamePad::XBoxController::SetDeadzone(unsigned int radius) {
	this->dead_zone = radius;
}

void GamePad::XBoxController::update_gamepad() {
	this->xinput->XInputGetState(this->id, this->pState);
}


