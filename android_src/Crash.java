package org.godotengine.godot;

import android.app.Activity;
import android.content.Context;

import com.crashlytics.android.Crashlytics;
import com.crashlytics.android.ndk.CrashlyticsNdk;
import io.fabric.sdk.android.Fabric;

import com.google.firebase.FirebaseApp;

public class Crash {

    public static Crash getInstance (Activity p_activity) {
		if (mInstance == null) {
			synchronized (Crash.class) {
				mInstance = new Crash(p_activity);
			}
		}

		return mInstance;
	}

	public Crash(Activity p_activity) {
		activity = p_activity;
	}

	public void init (FirebaseApp firebaseApp) {
		mFirebaseApp = firebaseApp;

		final Fabric fabric = new Fabric.Builder(activity)
                .kits(new Crashlytics(), new CrashlyticsNdk())
                .build();
		Fabric.with(fabric);
	}

	public void crash() {
		if (!isInitialized()) return;
		Crashlytics.getInstance().crash();
	}

	public void log(final String message) {
		if (!isInitialized()) return;
		Crashlytics.getInstance().log(message);
	}

	public void setString(String key, String value) {
		if (!isInitialized()) return;
		Crashlytics.getInstance().setString(key, value);
	}

	public void setBool(String key, boolean value) {
		if (!isInitialized()) return;
		Crashlytics.getInstance().setBool(key, value);
	}

	public void setReal(String key, double value) {
		if (!isInitialized()) return;
		Crashlytics.getInstance().setDouble(key, value);
	}

	public void setInt(String key, int value) {
		if (!isInitialized()) return;
		Crashlytics.getInstance().setInt(key, value);
	}

	public void setUserId(String id) {
		if (!isInitialized()) return;
		Crashlytics.getInstance().setUserIdentifier(id);
	}

	private boolean isInitialized() {
		return mFirebaseApp != null;
	}

    private static Context context;
	private static Activity activity;

	private FirebaseApp mFirebaseApp = null;

	private static Crash mInstance = null;
}
