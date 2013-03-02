package com.entity;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;

@Entity(name = "feed")
public class FeedEntity {

	@Id
	@GeneratedValue
	private long feedId;
	private String feed;
	private String userName;

	@ManyToMany(cascade = { CascadeType.REFRESH })
	@JoinTable(name = "FEED_CATEGORY", joinColumns = { @JoinColumn(name = "FEEDID") }, inverseJoinColumns = { @JoinColumn(name = "CATEGORYID") })
	private List<CategoryEntity> categoryEntityList = new ArrayList<CategoryEntity>();

	public String getUserName() {
		return userName;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public long getFeedId() {
		return feedId;
	}

	public void setFeedId(long feedId) {
		this.feedId = feedId;
	}

	public String getFeed() {
		return feed;
	}

	public void setFeed(String feed) {
		this.feed = feed;
	}

	public List<CategoryEntity> getCategoryEntityList() {
		return categoryEntityList;
	}

	public void setCategoryEntityList(List<CategoryEntity> categoryEntityList) {
		this.categoryEntityList = categoryEntityList;
	}

}
