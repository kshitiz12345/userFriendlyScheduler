package com.domain;

public class UserDomain {

	private long userId;
	private String name;
	private String emailId;
	private int numberOfFeedsUsed;
	
	public int getNumberOfFeedsUsed() {
		return numberOfFeedsUsed;
	}

	public void setNumberOfFeedsUsed(int numberOfFeedsUsed) {
		this.numberOfFeedsUsed = numberOfFeedsUsed;
	}

	public long getUserId() {
		return userId;
	}

	public void setUserId(long userId) {
		this.userId = userId;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getEmailId() {
		return emailId;
	}

	public void setEmailId(String emailId) {
		this.emailId = emailId;
	}

}
