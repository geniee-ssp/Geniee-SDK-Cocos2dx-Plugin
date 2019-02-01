package jp.co.geniee.gnadsdk.rewardvideo;

import android.app.Activity;

import jp.co.geniee.gnadsdk.rewardvideo.GNSRewardVideoAd;
import jp.co.geniee.gnadsdk.rewardvideo.GNSRewardVideoAdListener;
import jp.co.geniee.gnadsdk.rewardvideo.GNSVideoRewardData;

public class GNSRewardActivityBridge {

	private static Activity mActivity;
	private static GNSRewardVideoAd mReward;

	// cocos2dxへのcallback
	public static native void rewardVideoAdDidReceiveAd();
	public static native void rewardVideoAdDidStartPlaying();
	public static native void didRewardUserWithReward(String rewardType, double rewardAmount);
	public static native void rewardVideoAdDidClose();
	public static native void didFailToLoadWithError(String errorMsg);

	private static class CCGNSRewardVideoAdDelegate implements GNSRewardVideoAdListener {

		public CCGNSRewardVideoAdDelegate() {
		}

		@Override
		public void rewardVideoAdDidReceiveAd() {
			GNSRewardActivityBridge.rewardVideoAdDidReceiveAd();
		}

		@Override
		public void rewardVideoAdDidStartPlaying(GNSVideoRewardData data) {
			GNSRewardActivityBridge.rewardVideoAdDidStartPlaying();
		}

		@Override
		public void didRewardUserWithReward(GNSVideoRewardData data) {
			GNSRewardActivityBridge.didRewardUserWithReward(data.type, data.amount);
		}

		@Override
		public void didFailToLoadWithError(GNSVideoRewardException e) {
			GNSRewardActivityBridge.didFailToLoadWithError(e.getMessage());
		}

		@Override
		public void rewardVideoAdDidClose(GNSVideoRewardData data) {
			GNSRewardActivityBridge.rewardVideoAdDidClose();
		}
	}

	public GNSRewardActivityBridge(Activity activity) {
		mActivity = activity;
	}

	public static void initialize(final String zoneId) {
		mActivity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				mReward = new GNSRewardVideoAd(zoneId, mActivity);
				mReward.setRewardVideoAdListener(new CCGNSRewardVideoAdDelegate());

			}
		});
	}
	
	public static void loadRequest() {
		mActivity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if (mReward != null) {
					mReward.onStart();
					mReward.onResume();
					mReward.loadRequest();
				}
			}
		});
	}

	public static boolean canShow() {
		if (mReward != null) {
			return mReward.canShow();
		}
		return false;
	}

	public static void show() {
		mActivity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if (mReward != null) {
					mReward.show();
				}
			}
		});
	}

	public void onStart() {
		if (mReward != null) {
			mReward.onStart();
		}
	}

	public void onResume() {
		if (mReward != null) {
			mReward.onResume();
		}
	}

	public void onPause() {
		if (mReward != null) {
			mReward.onPause();
		}
	}

	public void onStop() {
		if (mReward != null) {
			mReward.onStop();
		}
	}

	public void onDestroy() {
		if (mReward != null) {
			mReward.onDestroy();
		}
	}
}
