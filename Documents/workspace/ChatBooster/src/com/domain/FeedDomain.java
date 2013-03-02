package com.domain;

import java.util.ArrayList;
import java.util.List;

import javax.validation.constraints.NotNull;

import org.hibernate.validator.constraints.NotEmpty;

public class FeedDomain {

	private long feedId;
	@NotEmpty
	private String feed;
	private String userName;
	@NotEmpty
	@NotNull
	private Long[] category;
	List<CategoryDomain> categoryDomainList = new ArrayList<CategoryDomain>();

	public Long[] getCategory() {
		return category;
	}

	public void setCategory(Long[] category) {
		this.category = category;
	}

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

	public List<CategoryDomain> getCategoryDomainList() {
		return categoryDomainList;
	}

	public void setCategoryDomainList(List<CategoryDomain> categoryDomainList) {
		this.categoryDomainList = categoryDomainList;
	}

}
