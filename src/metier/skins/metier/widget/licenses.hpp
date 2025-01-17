// Copyright (c) 2019-2024 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <QDialog>
#include <QMetaObject>
#include <memory>

class QItemSelection;
class QWidget;

namespace metier
{
namespace common
{
namespace model
{
class Licenses;
}  // namespace model
}  // namespace common
}  // namespace metier

namespace Ui
{
class licenseViewer;
}

namespace metier::skins::metier::widget
{
class Licenses final : public QDialog
{
    Q_OBJECT

public:
    Licenses(QWidget* parent);

    ~Licenses() final;

private Q_SLOTS:
    void component_changed(
        const QItemSelection& current,
        const QItemSelection& old);

private:
    std::unique_ptr<common::model::Licenses> model_;
    std::unique_ptr<Ui::licenseViewer> ui_;
};
}  // namespace metier::skins::metier::widget
