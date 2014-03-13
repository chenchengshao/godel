/*
 * robot_blending_panel.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: ros developer 
 */

#include "godel_plugins/rviz_panels/robot_blending_panel.h"

namespace godel_plugins {
namespace rviz_panels {

RobotBlendingPanel::RobotBlendingPanel(QWidget *parent):
		rviz::Panel(parent)
 {
	// TODO Auto-generated constructor stub
}

RobotBlendingPanel::~RobotBlendingPanel() {
	// TODO Auto-generated destructor stub
	widget_ = new widgets::RobotBlendingWidget();
}

void RobotBlendingPanel::onInitialize()
{
	// creating main layout
	widget_ = new widgets::RobotBlendingWidget();
	this->parentWidget()->resize(widget_->width(),widget_->height());
	QHBoxLayout* main_layout = new QHBoxLayout(this);
	main_layout->addWidget(widget_);

}

void RobotBlendingPanel::load(const rviz::Config& config)
{
	rviz::Panel::load(config);
	QString text_entry;
	ROS_INFO_STREAM("Reading config file");
	if(config.mapGetString("TextEntry",&text_entry))
	{
		ROS_INFO_STREAM("Loaded TextEntry with value: "<<text_entry.toStdString());
	}
	ROS_INFO_STREAM("Finish reading config file");
}

void RobotBlendingPanel::save(rviz::Config config) const
{
	ROS_INFO_STREAM("Saving configuration");
	rviz::Panel::save(config);
	config.mapSetValue("TextEntry",QString::fromStdString( std::string("test_field")));
}

} /* namespace rviz_panels */
} /* namespace godel_plugins */

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(godel_plugins::rviz_panels::RobotBlendingPanel,rviz::Panel )