package com.entity;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.ManyToMany;

@Entity(name = "category")
public class CategoryEntity {

	@Id
	@GeneratedValue
	private long categoryId;
	private String category;
	@ManyToMany(mappedBy = "categoryEntityList")
	private List<FeedEntity> feedEntityList = new ArrayList<FeedEntity>();

	@ManyToMany(mappedBy = "categoryEntityList")
	private List<EmailEntity> emailEntityList = new ArrayList<EmailEntity>();

	public List<FeedEntity> getFeedEntityList() {
		return feedEntityList;
	}

	public void setFeedEntityList(List<FeedEntity> feedEntityList) {
		this.feedEntityList = feedEntityList;
	}

	public List<EmailEntity> getEmailEntityList() {
		return emailEntityList;
	}

	public void setEmailEntityList(List<EmailEntity> emailEntityList) {
		this.emailEntityList = emailEntityList;
	}

	public long getCategoryId() {
		return categoryId;
	}

	public void setCategoryId(long categoryId) {
		this.categoryId = categoryId;
	}

	public String getCategory() {
		return category;
	}

	public void setCategory(String category) {
		this.category = category;
	}

}
