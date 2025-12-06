#pragma once
#include "KC.h"
#include <chrono>
#include <format>
#include <string>
#include <unordered_map>

using namespace chrono;

class FileManager
{
public:

	void RepairPipeForEdit(unordered_map<int, Pipes>& pipe);
	void ErasePipeForEdit(unordered_map<int, Pipes>& pipe);
	void EditPipe(unordered_map<int, Pipes>& pipe);
	void RepairKC(unordered_map<int, KC>& kc);
	void EraseKC(unordered_map<int, KC>& kc);
	void EditKC(unordered_map<int, KC>& kc);
	void ErasePipes(unordered_map<int, Pipes>& pipes, vector<int>& id_p);
	void RepairPipes(unordered_map<int, Pipes>& pipes, vector<int>& id_p);
	void FilterEditIdPipes(unordered_map<int, Pipes>& pipes, vector<int>& id_p);
	template <typename T, typename Filter, typename Param>
	auto find_by_filter(const unordered_map<int, T>& objects, Filter filter, Param param);
	void NameFilterPipe(unordered_map<int, Pipes>& pipes);
	void RepairPipe(unordered_map<int, Pipes>& pipes);
	void FilterPipe(unordered_map<int, Pipes>& pipes);
	void FilterEditIdKC(unordered_map<int, KC>& kc, vector<int>& id_kc);
	void FilterIdleWorkshopsKC(unordered_map<int, KC>& kc);
	void FilterNameKC(unordered_map<int, KC>& kc);
	void FilterKC(unordered_map<int, KC>& kc);
	void SaveAll(const unordered_map<int, Pipes>& pipes,
		const unordered_map<int, KC>& stations,
		const string& filename);
	void LoadAll(unordered_map<int, Pipes>& pipes,
		unordered_map<int, KC>& stations,
		const std::string& filename);
	void PrintKcPipe(unordered_map<int, Pipes>& pipe, unordered_map<int, KC>& kc);

};