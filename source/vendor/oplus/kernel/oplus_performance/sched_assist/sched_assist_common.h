/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2020 Oplus. All rights reserved.
 */
#ifndef _OPLUS_SCHED_COMMON_H_
#define _OPLUS_SCHED_COMMON_H_

extern int sysctl_uifirst_enabled;
extern int sysctl_launcher_boost_enabled;
extern int sysctl_slide_boost_enabled;

enum INHERIT_UX_TYPE
{
	INHERIT_UX_BINDER = 0,
	INHERIT_UX_RWSEM,
	INHERIT_UX_MUTEX,
	INHERIT_UX_SEM,
	INHERIT_UX_FUTEX,
	INHERIT_UX_MAX,
};

enum SCHED_ASSIST_SCENE
{
	SA_LAUNCH = 0,
	SA_SLIDE,
	SA_MAX,
};

static inline bool sched_assist_scene(unsigned int scene)
{
	if (unlikely(!sysctl_uifirst_enabled))
		return false;

	switch (scene) {
		case SA_LAUNCH:
			return sysctl_launcher_boost_enabled;
		case SA_SLIDE:
			return sysctl_slide_boost_enabled;
		default:
			return false;
	}
}
#endif
