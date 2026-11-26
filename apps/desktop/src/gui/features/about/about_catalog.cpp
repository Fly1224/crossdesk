/*
 * @Author: DI JUNKUN
 * @Date: 2026-10-21
 * Copyright (c) 2026 by DI JUNKUN, All Rights Reserved.
 */

#include "about_catalog.h"

#include <nlohmann/json.hpp>

#include <iterator>
#include <memory>
#include <string>
#include <vector>

#include "about_resources.h"

namespace crossdesk::about {
namespace {

const nlohmann::json& Catalog() {
  static const auto catalog = nlohmann::json::parse(
      std::begin(kAboutResources), std::end(kAboutResources));
  return catalog;
}

}  // namespace

void SetInstalledReleaseNotes(const slint::ComponentHandle<ui::MainWindow>& window,
                              const std::string& language) {
  const auto& notes = Catalog().at("releaseNotes");
  const auto& lines = notes.contains(language) ? notes.at(language) : notes.at("en-US");
  std::vector<slint::SharedString> highlights;
  for (const auto& line : lines) {
    highlights.emplace_back(line.get<std::string>());
  }
  window->set_installed_release_notes(
      std::make_shared<slint::VectorModel<slint::SharedString>>(highlights));
}

}  // namespace crossdesk::about
